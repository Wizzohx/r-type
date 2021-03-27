#include <iostream>
#include "menu.hpp"
#include "mainGame.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "R-TYPE");

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                menu.MoveUp();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                menu.MoveDown();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                switch (menu.GetPressedItem())
                {
                case 0:
                    window.close();
                    run();
                    break;
                case 1:
                    std::cout << "options button" << std::endl;
                    break;
                case 2:
                    window.close();                
                    break;
                default:
                    break;
                }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
    return (0);
}