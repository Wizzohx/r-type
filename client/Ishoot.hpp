#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <cstdlib>


class Ishoot
{
protected:
    float maxSpeed;
    float radius;
public:
    virtual void setMaxSpeed(float speed) = 0;
    virtual float getmaxSpeed() = 0;
    virtual float getRadius() = 0;
    virtual void setRadius(float rad) = 0;
};