use std::{io::Write, net::TcpStream};

use prost::Message;

use crate::{command, led_ctr, tcp_tools::PeerInfo};

fn led_on() -> (bool, String) {
    (led_ctr::set_leds(true), String::from("LED ON"))
}

fn led_off() -> (bool, String) {
    (led_ctr::set_leds(false), String::from("LED OFF"))
}

fn socket_info(connection: &mut TcpStream) -> (bool, String) {
    let server_info = connection.local_addr().unwrap();
    (
        true,
        format!(
            "IP:{} | PORT:{}\n\0",
            server_info.ip().to_string(),
            server_info.port().to_string()
        ),
    )
}

fn unknown_command() -> (bool, String) {
    (false, String::from("???"))
}

pub fn evaluate_command(connection: &mut TcpStream, msg: &[u8]) -> bool {
    let msg = command::carrier::CommandCarrier::decode(msg).expect("NO CARRIER");
    println!("msglen: {}", msg.msg_len);

    let msg = msg.payload.expect("NO PAYLOAD").command;

    let resp: (bool, String);
    if msg == command::msg::Command::LedOn as i32 {
        resp = led_on();
    } else if msg == command::msg::Command::LedOff as i32 {
        resp = led_off();
    } else if msg == command::msg::Command::Info as i32 {
        resp = socket_info(connection);
    } else if msg == command::msg::Command::Exit as i32 {
        println!("Client {} disconnected.", connection.peer_info_string());
        return true;
    } else {
        resp = unknown_command();
    }

    let mut response = command::carrier::ResponseCarrier::default();
    let payload = command::response::ResponseMessage {
        is_successful: resp.0,
        message: resp.1,
    };
    response.msg_len = u32::try_from(payload.encoded_len()).unwrap();
    response.payload = Some(payload);
    let mut response_encoded: Vec<u8> = Vec::new();
    response
        .encode(&mut response_encoded)
        .expect("Message could not be encoded.");

    response_encoded.push(0);

    connection
        .write(&response_encoded.as_slice())
        .expect("Message sending error.");
    println!(
        "{} Transmitted:[{}] bytes",
        connection.peer_info_string(),
        response_encoded.len() - 1,
    );
    return false;
}
