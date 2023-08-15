fn main() -> Result<(), std::io::Error> {
    prost_build::compile_protos(
        &["src/protobuf/command.proto", "src/protobuf/carrier.proto", "src/protobuf/response.proto"],
        &["src/protobuf"],
    )
}
