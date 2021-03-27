/*
** EPITECH PROJECT, 2020
** B-CPP-500-NCY-5-1-babel-thomas.voster-master
** File description:
** client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <vector>
#include <string>
//#include <array>
#include <boost/asio.hpp>
//#include <boost/array.hpp>

class Icclient {
    public:
        virtual void sendPseudo(std::string data) = 0;
        virtual void handleMsg(std::string data) = 0;
        virtual void receive() = 0;
        virtual void stop() = 0;
        virtual void setEndpoint(std::string end_) = 0;
        virtual void setPort(int port_) = 0;
        virtual int getPort() = 0;
    protected:
        std::string endpoint;
        std::array<char, 512> buffer;
        int port;
        void *serv;
        int nameless = 0;
};

class cclient : private Icclient {
    public:
        std::string pseudo;
        boost::asio::ip::tcp::socket *sock;

        cclient(void *_serv, boost::asio::ip::tcp::socket *sock);
        ~cclient();

        void send(std::string data, std::vector<cclient*> listc);
        void sendPseudo(std::string data);
        void handleMsg(std::string data);
        void receive();
        void stop();
        void setEndpoint(std::string end_);
        void setPort(int port_);
        int getPort();
};

#endif /* !CLIENT_HPP_ */