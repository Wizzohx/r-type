/*
** EPITECH PROJECT, 2020
** r-type
** File description:
** client
*/

#include "include/client.hpp"
#include "include/ennemy.hpp"

cclient::cclient()
{
	used = 0;
}

cclient::~cclient()
{
	this->used = 0;
}

void cclient::setused(int temp)
{
	this->used = temp;
}

int cclient::getused()
{
	return (this->used);
}

void ennemy::setx2(float temp)
{
	this->x = temp;
}

float ennemy::getx2()
{
	return (this->x);
}

void ennemy::sety2(float temp)
{
	this->y = temp;
}

float ennemy::gety2()
{
	return (this->y);
}

void ennemy::setused2(bool temp)
{
	this->used = temp;
}

bool ennemy::getused2()
{
	return (this->used);
}