use std::sync::mpsc::channel;
use std::thread::JoinHandle;
use std::{env, net::TcpListener};
use tcp_app::tcp_tools::SocketInfo;
use tcp_app::{led_ctr, tcp_tools};


fn main() {
    let (finished_notifier_t, finished_notifier_r) = channel();
    // Initialize the CTRL-C handler

    led_ctr::initialize_leds();
    let mut threads: Vec<JoinHandle<()>> = Vec::new();

    let port = get_port_from_cmd_or_panic();
    let listener_server = tcp_tools::create_server_or_panic(port, true);

    print_startup_message(&listener_server);

    loop {
        let new_connection = match listener_server.accept() {
            Ok(connected_socket) => connected_socket.0,
            Err(err) => {
                println!("Connection to peer failed: {}", err);
                continue;
            }
        };
        let new_thread =
            tcp_tools::launch_new_socket_thread(new_connection, finished_notifier_t.clone());
        threads.push(new_thread);
        if finished_notifier_r.try_recv().is_ok() {
            threads.clean_dead_threads();
        }
    }
}

#[inline]
fn get_port_from_cmd_or_panic() -> String {
    env::args()
        .nth(1)
        .expect("Program needs a PORT as an argument")
}

#[inline]
fn print_startup_message(listener_server: &TcpListener) {
    println!("Rust TCP Server v{}", env!("CARGO_PKG_VERSION"));
    println!("Server Info: {}", listener_server.self_info_string());
}

trait Cleanup {
    fn clean_dead_threads(&mut self);
}

impl Cleanup for Vec<JoinHandle<()>> {
    fn clean_dead_threads(&mut self) {
        self.retain(|thread| !thread.is_finished());
    }
}
