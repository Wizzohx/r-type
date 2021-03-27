#include "player.hpp"


player::player()
{
    Left = "oui";
    Right = "oui";
    Ahead = "oui";
    Behind = "oui";
}

player::player(std::string left, std::string right, std::string ahead, std::string behind) {
    Left = left;
    Right = right;
    Ahead = ahead;
    Behind = behind;
}
    
player::~player()
{
    
}

int player::getId()
{
    return (Id);
}

void player::setId(int i)
{
    Id = i;
}

void player::setHealth(int sante)
{
    Health = sante;
}


int player::getHealth()
{
    return (Health);
}

void player::setSize(float radius)
{
    j.setRadius(radius);
}

void player::moveLeft()
{
    j.move(-10.f, 0.f);
}

void player::moveRight()
{
    j.move(10.f, 0.f);
}

void player::moveAhead()
{
    j.move(0.f, -10.f);
}

void player::moveBehind()
{
    j.move(0.f, 10.f);
}

void player::setColor(const sf::Color &color)
{
    j.setFillColor(color);
}

void player::setPosX(float xy)
{
    x = xy;
}

void player::setPosY(float xy)
{
    y = xy;
    j.setPosition(sf::Vector2f(x, xy));
}

void setPosY(float x);

void player::setCursor(sf::Vector2i i)
{
    playerCenter = sf::Vector2f(j.getPosition().x + j.getRadius(), j.getPosition().y + j.getRadius());
    mousePosWindow = sf::Vector2f(i);
    aimDir = mousePosWindow - playerCenter;
    //aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

const sf::CircleShape player::getShape()
{
    return (j);
}

sf::Vector2f player::getPlayerCenter()
{
    return (playerCenter);
}

sf::Vector2f player::getaimDirNorm()
{
    return (aimDirNorm);
}
