#include "Iplayer.hpp"

class ennemies : public Iplayer
{
public:
    ennemies();
    ennemies(std::string left, std::string right, std::string ahead, std::string behind);
    ~ennemies();
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
    void setSprite();
    void setSprite2();
    const sf::RectangleShape getShape();
    sf::Vector2f getPlayerCenter();
    sf::Vector2f getaimDirNorm();
    sf::Sprite sprite;
    sf::Texture texture;
private:
    sf::RectangleShape j;
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    float x;
    float y;
};
