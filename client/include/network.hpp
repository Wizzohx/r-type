/*
** EPITECH PROJECT, 2020
** B-CPP-500-NCY-5-1-babel-thomas.voster-master
** File description:
** network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <boost/asio.hpp>
#include <boost/array.hpp>

class INetwork {
    public:
        class SocketEvent {
            public:
                virtual ~SocketEvent() {}
        };
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void setSock(INetwork::SocketEvent *listen) = 0;
        virtual void setPort(int _port) = 0;
        virtual int getPort() = 0;
        virtual void setServ(void *_serv) = 0;
        virtual void *getServ() = 0;
        virtual void setRun(bool _run) = 0;
        virtual bool getRun() = 0;
    protected:
        int port;
        void *serv;
        bool running;
};

class network : private INetwork {
    public:
        std::vector<boost::asio::ip::udp::socket*> socket;
        boost::asio::io_service io_service;
        INetwork::SocketEvent* listen;
        boost::system::error_code err;

        network(void *serv_, int port_);
        network();
        ~network();

        void start();
        void stop();
        void net_accept();
        void setSock(INetwork::SocketEvent *listen);
        void setPort(int _port);
        int getPort();
        void setServ(void *_serv);
        void *getServ();
        void setRun(bool _run);
        bool getRun();
};

#endif /* !NETWORK_HPP_ */