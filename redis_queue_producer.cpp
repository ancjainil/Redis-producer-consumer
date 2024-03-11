// redis_queue_producer.cpp
#include <iostream>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/use_future.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/algorithm/string.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve("localhost", "6379"));

        std::string input;
        std::cout << "Enter message to push into Redis queue: ";
        std::getline(std::cin, input);

        // Format the command to push to the Redis queue
        std::string command = "LPUSH my_queue " + input + "\r\n";
        
        write(socket.native_handle(), boost::asio::buffer(command).data(), command.size());




        std::cout << "Message pushed to Redis queue successfully." << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
