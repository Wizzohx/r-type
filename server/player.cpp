/*
** EPITECH PROJECT, 2020
** r-type
** File description:
** player
*/

#include "include/player.hpp"

player::player()
{
    this->x = -1000;
    this->y = -1000;
    this->bx = -100;
    this->by = -100;
    this->isshooted = false;
}

player::~player()
{
}

void player::kill_player() {
    this->x = -10000;
    this->y = -10000;
}

void player::shoot()
{
    bx = x;
    by = y;
    isshooted = true;
}

void player::destroy_shoot()
{
    bx = -100;
    by = -100;
    isshooted = false;
}

void player::setx(float temp)
{
    this->x = temp;
}

float player::getx()
{
    return (this->x);
}

void player::sety(float temp)
{
    this->y = temp;
}

float player::gety()
{
    return (this->y);
}

void player::setbx(float temp)
{
    this->bx = temp;
}

float player::getbx()
{
    return (this->bx);
}

void player::setby(float temp)
{
    this->by = temp;
}

float player::getby()
{
    return (this->by);
}

void player::setisshooted(bool temp)
{
    this->isshooted = temp;
}

bool player::getisshooted()
{
    return (this->isshooted);
}