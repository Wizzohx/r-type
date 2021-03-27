/*
** EPITECH PROJECT, 2020
** inter
** File description:
** Iplayer
*/

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <cstdlib>


class Iplayer
{
private:
    /* data */
public:
    virtual int getId() = 0;
    virtual void setId(int i) = 0;
    virtual void setSize(float radius) = 0;
    virtual void setHealth(int sante) = 0;
    virtual int getHealth() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveAhead() = 0;
    virtual void moveBehind() = 0;
protected:
    int Id;
    int Health;
    std::string Left;
    std::string Right;
    std::string Ahead;
    std::string Behind;
};


#endif /* !IPLAYER_HPP_ */
