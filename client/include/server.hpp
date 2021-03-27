/*
** EPITECH PROJECT, 2020
** B-CPP-500-NCY-5-1-babel-thomas.voster-master
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <vector>
#include <iostream>
#include <signal.h>
#include <boost/asio.hpp>
#include <boost/array.hpp>

#include "client.hpp"
#include "network.hpp"

class Iserver {
    public:

        virtual void client_connected() = 0;
        virtual void close_client(std::string pseudo) = 0;
        virtual cclient *search_client(std::string pseudo) = 0;
        virtual void connection() = 0;
        virtual void stop() = 0;
        virtual void setStart(bool start_) = 0;
        virtual bool getStart() = 0;
        virtual void setNet(network *start_) = 0;
        virtual network *getNet() = 0;
    protected:
        bool start;
        network *net;
};

class server : private Iserver {
    public:
        server(int port);
        ~server();
    
        void client_connected();
        void close_client(std::string pseudo);
        cclient *search_client(std::string pseudo);
        void connection();
        void stop();
        void setStart(bool start_);
        bool getStart();
        void setNet(network *start_);
        network *getNet();
};

#endif /* !SERVER_HPP_ */