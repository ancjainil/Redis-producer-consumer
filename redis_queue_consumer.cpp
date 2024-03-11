// redis_queue_consumer.cpp
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

        // Format the command to pop from the Redis queue
        std::string command = "RPOP my_queue\r\n";
        write(socket.native_handle(), boost::asio::buffer(command).data(), command.size());

        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        std::string data = boost::asio::buffer_cast<const char*>(response.data());
        boost::algorithm::trim(data);

        if (!data.empty()) {
            std::cout << "Message popped from Redis queue: " << data << std::endl;
        } else {
            std::cout << "Redis queue is empty." << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

