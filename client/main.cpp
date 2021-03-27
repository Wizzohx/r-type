/*
** EPITECH PROJECT, 2020
** r-type
** File description:
** main
*/

#include <boost/asio.hpp>
#include <iostream>

//IDJOUEUR|x0/y0/x1/y1/x2/y2/x3/y3|x0/y0/...|shoot

void parse_str(char *recvbuf)
{

}

int main()
{
    try
    {
        boost::asio::io_context io_context;

        boost::asio::ip::udp::socket socket{io_context};
        socket.open(boost::asio::ip::udp::v4());
        socket.send_to(boost::asio::buffer("connection"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        while(1) {
            char recv_buf[1024];
            boost::asio::ip::udp::endpoint sender_endpoint;
			size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
			std::cout << recv_buf << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}