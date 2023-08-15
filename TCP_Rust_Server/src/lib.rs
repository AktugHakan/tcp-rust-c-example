pub mod commands;
pub mod led_ctr;
pub mod tcp_tools;

pub mod command {
    pub mod msg {
        include!(concat!(env!("OUT_DIR"), "/command.msg.rs"));
    }

    pub mod response
    {
        include!(concat!(env!("OUT_DIR"), "/command.response.rs"));
    }

    pub mod carrier {
        include!(concat!(env!("OUT_DIR"), "/command.carrier.rs"));
    }
}
