#include "ennemies.hpp"


ennemies::ennemies()
{
    Left = "oui";
    Right = "oui";
    Ahead = "oui";
    Behind = "oui";
}

ennemies::ennemies(std::string left, std::string right, std::string ahead, std::string behind) {
    Left = left;
    Right = right;
    Ahead = ahead;
    Behind = behind;
}
    
ennemies::~ennemies()
{
    
}

int ennemies::getId()
{
    return (Id);
}

void ennemies::setId(int i)
{
    Id = i;
}

void ennemies::setHealth(int sante)
{
    Health = sante;
}


int ennemies::getHealth()
{
    return (Health);
}

void ennemies::setSize(float radius)
{
    j.setSize(sf::Vector2f(radius, radius));
}

void ennemies::moveLeft()
{
    j.move(-10.f, 0.f);
}

void ennemies::moveRight()
{
    j.move(10.f, 0.f);
}

void ennemies::moveAhead()
{
    j.move(0.f, -10.f);
}

void ennemies::moveBehind()
{
    j.move(0.f, 10.f);
}

void ennemies::setColor(const sf::Color &color)
{
    j.setFillColor(color);
}

void ennemies::setPosX(float xy)
{
    x = xy;
}

void ennemies::setPosY(float xy)
{
    y = xy;
    j.setPosition(sf::Vector2f(x, xy));
    sprite.setPosition(sf::Vector2f(x, xy));
}

void ennemies::setCursor(sf::Vector2i i)
{
    //playerCenter = sf::Vector2f(j.getPosition().x + j.getRadius(), j.getPosition().y + j.getRadius());
    //mousePosWindow = sf::Vector2f(i);
    //aimDir = mousePosWindow - playerCenter;
    //aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

const sf::RectangleShape ennemies::getShape()
{
    return (j);
}

sf::Vector2f ennemies::getPlayerCenter()
{
    return (playerCenter);
}

sf::Vector2f ennemies::getaimDirNorm()
{
    return (aimDirNorm);
}

void ennemies::setSprite()
{
    texture.loadFromFile("../en1.png");
    sprite.setTexture(texture);
    sprite.scale(2,2);
}

void ennemies::setSprite2()
{
    texture.loadFromFile("../en2.png");
    sprite.setTexture(texture);
    sprite.scale(1,1);
}