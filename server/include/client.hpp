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
#include <boost/asio.hpp>

class Icclient {
    public:
        virtual void setused(int temp) = 0;
        virtual int getused() = 0;
    protected:
        int used;
};

class cclient : public Icclient {
    public:
        cclient();
        ~cclient();
        
        void setused(int temp);
        int getused();

        boost::asio::ip::udp::endpoint endpoint;
};

#endif /* !CLIENT_HPP_ */