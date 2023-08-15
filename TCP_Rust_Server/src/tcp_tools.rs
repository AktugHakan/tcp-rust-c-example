use std::{
    io::Read,
    net::{TcpListener, TcpStream},
    process,
    sync::mpsc::Sender,
    thread::{self, JoinHandle},
};

use crate::commands;

pub fn create_server_or_panic(port: String, blocking: bool) -> TcpListener {
    let ip_port = "0.0.0.0:".to_string() + &port;
    let server = match TcpListener::bind(ip_port) {
        Ok(server) => server,
        Err(err) => match err.kind() {
            std::io::ErrorKind::InvalidInput => panic!("Port is not valid."),
            std::io::ErrorKind::PermissionDenied => panic!("Binding port {} has failed.", port),
            _ => panic!("Couldn't create server."),
        },
    };
    server
        .set_nonblocking(!blocking)
        .expect("Switching blocking modes failed.");
    server
}

pub fn check_command(connection: &mut TcpStream) -> bool {
    let mut msg: Vec<u8> = vec![0; 100];
    match connection.read(&mut msg) {
        Ok(size) => {
            if size == 0 {
                println!(
                    "Client {} has droppped connection.",
                    connection.peer_info_string()
                );
                return true; // die = true if connection is broken
            }
            let msg = &msg[0..size - 1];
            println!(
                "{} Recieved:{} bytes",
                connection.peer_info_string(),
                msg.len()
            );
            return commands::evaluate_command(connection, msg);
        }
        Err(err) => {
            println!("Data recieving failed: {}", err);
            return err.kind() == std::io::ErrorKind::NotConnected
                || err.kind() == std::io::ErrorKind::BrokenPipe
                || err.kind() == std::io::ErrorKind::ConnectionAborted;
        }
    }
}

pub fn launch_new_socket_thread(
    mut socket: TcpStream,
    finished_notifier_t: Sender<bool>,
) -> JoinHandle<()> {
    let thread_join_handle = thread::spawn(move || loop {
        let die = check_command(&mut socket);
        if die {
            finished_notifier_t.send(true).unwrap();
            break;
        }
        println!("═══════════════════════════════");
    });
    return thread_join_handle;
}

pub trait PeerInfo {
    fn peer_info_string(&self) -> String;
}
pub trait SocketInfo {
    fn self_info_string(&self) -> String;
}

impl SocketInfo for TcpListener {
    fn self_info_string(&self) -> String {
        let server_info = self
            .local_addr()
            .expect("Listener server info could not obtained.");

        format!(
            "PID:{} | IP:{} | PORT:{}",
            process::id(),
            server_info.ip().to_string(),
            server_info.port().to_string()
        )
    }
}

impl SocketInfo for TcpStream {
    fn self_info_string(&self) -> String {
        let server_info = self
            .local_addr()
            .expect("Connected server info could not obtained.");

        format!(
            "IP:{} | PORT:{}",
            server_info.ip().to_string(),
            server_info.port().to_string()
        )
    }
}

impl PeerInfo for TcpStream {
    fn peer_info_string(&self) -> String {
        let server_info = self.peer_addr().expect("Peer info could not obtained.");

        format!(
            "IP:{} | PORT:{}",
            server_info.ip().to_string(),
            server_info.port().to_string()
        )
    }
}
