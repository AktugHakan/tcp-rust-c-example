use std::{fs::File, io::Write};

pub fn initialize_leds() {
    for i in 0..4 {
        let mut led_config_file =
            match File::create(format!("/sys/class/leds/beaglebone:green:usr{i}/trigger")) {
                Ok(file) => file,
                Err(err) => match err.kind() {
                    std::io::ErrorKind::PermissionDenied => {
                        panic!("Accessing LED{i} SYSFS 'trigger' file denied.");
                    }
                    std::io::ErrorKind::NotFound => {
                        println!("This device does not have LEDs.");
                        return;
                    }
                    _ => panic!("Cannot open LED SYSFS trigger file"),
                },
            };

        led_config_file
            .write_all(b"none")
            .expect("LED SYSFS file is unwritable.");
    }

    for i in 0..4 {
        let mut led_state_file =
            match File::create(format!("/sys/class/leds/beaglebone:green:usr{i}/brightness")) {
                Ok(file) => file,
                Err(err) => match err.kind() {
                    std::io::ErrorKind::PermissionDenied => {
                        panic!("Accessing LED{i} SYSFS 'brightness' file denied.")
                    }
                    std::io::ErrorKind::NotFound => {
                        println!("This device does not have LEDs.");
                        return;
                    }
                    _ => panic!("Cannot open LED SYSFS brightness file"),
                },
            };

        led_state_file
            .write_all(b"0")
            .expect("LED SYSFS file is unwritable.");
    }
}

pub fn set_leds(light_on: bool) -> bool
{
    for i in 0..4 {
        let mut led_state_file =
            match File::create(format!("/sys/class/leds/beaglebone:green:usr{i}/brightness")) {
                Ok(file) => file,
                Err(err) => match err.kind() {
                    std::io::ErrorKind::PermissionDenied => {
                        panic!("LED SYSFS files are not accessible.")
                    }
                    std::io::ErrorKind::NotFound => {
                        println!("This device does not have LEDs.");
                        return false;
                    }
                    _ => panic!("Cannot open LED SYSFS file"),
                },
            };

        led_state_file
            .write_all(if light_on {b"1"} else {b"0"})
            .expect("LED SYSFS file is unwritable.");
    }
    true
}