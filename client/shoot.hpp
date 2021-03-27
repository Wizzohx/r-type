#include "Ishoot.hpp"

class shoot : public Ishoot
{
public:
    shoot();
    ~shoot();
    void setMaxSpeed(float speed);
    float getmaxSpeed();
    float getRadius();
    void setRadius(float rad);
    sf::CircleShape getShape();
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f value);
    void setMove();
    void setPosition(sf::Vector2f playerCenter);
protected:
    sf::CircleShape shape;
    sf::Vector2f currVelocity;
};
