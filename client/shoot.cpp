#include "shoot.hpp"

shoot::shoot()
{
    maxSpeed = 10.f;
    radius = 5.f;
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    currVelocity = sf::Vector2f(0.f,0.f);
}

shoot::~shoot()
{

}

void shoot::setMaxSpeed(float speed)
{
    maxSpeed = speed;
}

float shoot::getmaxSpeed()
{
    return (maxSpeed);
}

float shoot::getRadius()
{
    return (radius);
}

void shoot::setRadius(float rad)
{
    radius = rad;
    shape.setRadius(radius);
}

sf::CircleShape shoot::getShape()
{
    return (shape);
}

sf::Vector2f shoot::getVelocity()
{
    return (currVelocity);
}

void shoot::setVelocity(sf::Vector2f value)
{
    currVelocity = value;
}

void shoot::setMove()
{
    shape.move(currVelocity);
}

void shoot::setPosition(sf::Vector2f playerCenter)
{
    shape.setPosition(playerCenter);
}