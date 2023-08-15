#include <SocketManager/types.h>
#include <SocketManager/TCP.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <command.pb.h>
#include <carrier.pb.h>

using namespace SocketManager;

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Argument not sufficient";
            return 1;
        }
        TCPClientSocket my_client(Domain::IPV4, argv[1], 3169);

        std::string command("null");
        do
        {
            command::carrier::CommandCarrier carrier;

            std::cout << "_> " << std::flush;
            std::cin >> command;
            if (command == "info")
            {
                carrier.mutable_payload()->set_command(command::msg::Command::COMMAND_INFO);
            }
            else if (command == "on")
            {
                carrier.mutable_payload()->set_command(command::msg::Command::COMMAND_LED_ON);
            }
            else if (command == "off")
            {
                carrier.mutable_payload()->set_command(command::msg::Command::COMMAND_LED_OFF);
            }
            else if (command == "exit")
            {
                carrier.mutable_payload()->set_command(command::msg::Command::COMMAND_EXIT);
            }
            else
            {
                std::cout << "Unknown command!" << std::endl;
                continue;
            }

            carrier.set_msg_len(0);

            std::string serialized_message = carrier.SerializeAsString();

            my_client.send_string(serialized_message);
            std::cout << serialized_message.length() << " bytes sent." << std::endl;

            if (!command.compare("exit"))
            {
                printf("Closing.\n");
                break;
            }

            std::string recieved_buf = my_client.recieve_string(); // convert to protobuf
            command::carrier::ResponseCarrier response_carrier;

            std::cout << recieved_buf.length() << " bytes recieved." << std::endl;
            if (response_carrier.ParseFromString(recieved_buf))
            {
                command::response::ResponseMessage response = response_carrier.payload();
                if (response_carrier.msg_len() == response.ByteSizeLong())
                {
                    std::cout << (response.is_successful() ? "OK   |" : "FAIL |") << response.message() << std::endl;
                }
                else
                {
                    std::cout << "Server's response corrupted on air!" << std::endl;
                }
            }
            else
            {
                std::cout << "Server's response cannot be parsed!" << std::endl;
            }
        } while (true);

        return 0;
    }
    catch (const char *errmsg)
    {
        std::cerr << "ERROR: " << errmsg << std::endl;
        return 1;
    }
    catch (const std::string errmsg)
    {
        std::cerr << "ERROR: " << errmsg << std::endl;
        return 1;
    }
}
