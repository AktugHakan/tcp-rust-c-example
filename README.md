# Rust - C++ Protobuf Example
An example application that communicates over **TCP** using Google **Protocol Buffers**. This example controls built-in LEDs of BeagleBone Black hardware.

## Cloning Repo
This repo contains two seperate code bases:
- **Rust** for server side
- **C++** for client side
    - For client side, **C++** library ```Socket Manager``` as a git submodule.

To clone the repo and required submodules:
```bash
git clone --recurse-submodules https://github.com/AktugHakan/tcp-rust-c-example.git
```
If you cloned the repo without ```--recurse-modules``` flag, you can get the submodule using:
```bash
git submodule init
git submodule update
```

## Building C++ Client
C++ client is in the ```TCP_C_Client``` directory.
In this directory run
```bash
make
```
to build the client side program.  
Program is generated as ```build/main```.

### Cross-Compiling
Built-in Makefile also supports cross-compiling. To cross-compile the client program:
```bash
make CROSS_COMPILE=<compiler_prefix>
```
for example, if your cross-compiler is ```arm-linux-gnueabihf-gcc``` you should give ```arm-linux-gnueabihf-``` as compiler prefix argument.

## Building Rust Server
Rust server is in the ```TCP_Rust_Server``` directory.
In this directory run
```bash
cargo build
```
to build the server program.  
Program is generated as ```target/debug/tcp_app```.

### Cross-Compiling
Rust program and its libraries are fully cross-compilable. To cross compile:  
1. Set up cross-compiler  
In .cargo/config.toml change the ```linker``` argument according to your toolchain.
2. Build  
Build the server program using:
```bash
 cargo build --target=<your-target-platform>
```
To see supported target platforms check out [rustc Platform Support page](https://doc.rust-lang.org/nightly/rustc/platform-support.html).
