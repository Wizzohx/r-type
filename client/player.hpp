#include "Iplayer.hpp"

class player : public Iplayer
{
public:
    player();
    player(std::string left, std::string right, std::string ahead, std::string behind);
    ~player();
    int getId();
    void setId(int i);
    void setSize(float radius);
    void setHealth(int sante);
    int getHealth();
    void moveLeft();
    void moveRight();
    void moveAhead();
    void moveBehind();
    void setColor(const sf::Color &color);
    void setCursor(sf::Vector2i i);
    void setPosX(float xy);
    void setPosY(float xy);
    const sf::CircleShape getShape();
    sf::Vector2f getPlayerCenter();
    sf::Vector2f getaimDirNorm();
private:
    sf::CircleShape j;
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    float x;
    float y;
};
