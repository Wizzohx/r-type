/*
** EPITECH PROJECT, 2020
** B-CPP-501-NCY-5-1-rtype-antoine.mathis-main
** File description:
** mainGame
*/

#include "SFML/Audio.hpp"
#include "player.hpp"
#include "ennemies.hpp"
#include "shoot.hpp"
#include <boost/asio.hpp>
#include "mainGame.hpp"
#include <chrono>
#include <thread>


std::string get_id(char *recv_buf)
{
    std::string id;

    if (recv_buf[0] == '0')
        id = "0";
    if (recv_buf[0] == '1')
        id = "1";
    if (recv_buf[0] == '2')
        id = "2";
    if (recv_buf[0] == '3')
        id = "3";
    return (id);
}

std::vector<std::string> parse_info(char *recv_buf, std::vector<player> players)
{
    int i = 1;
    int index = 0;
    int is_good = 0;
    int y = -1;
 
    std::vector<std::string> floatss;

    for (int x = 1; recv_buf[x]; x++) {
        if (recv_buf[x] == '/') {
            floatss.push_back(std::string (""));
            y++;
        } else
            floatss[y] = floatss[y] + recv_buf[x];
    }
    return (floatss);
}

int check_collision_enemy(std::vector<player> bullets, std::vector<ennemies> ene)
{
    for (int i = 0; i < bullets.size(); i++) {
        for (size_t k = 0; k < ene.size(); k++) {
            if(bullets[i].getShape().getGlobalBounds().intersects(ene[k].getShape().getGlobalBounds())) {
                return (k);
            }
        }
    }
    return (-1);
}

int check_collision_players(std::vector<player> bullets, std::vector<ennemies> ene)
{
    for (int i = 0; i < bullets.size(); i++) {
        for (size_t k = 0; k < ene.size(); k++) {
            if((bullets[i].getShape().getPosition().y + 50.f) >= ene[k].getShape().getPosition().y && (bullets[i].getShape().getPosition().y - 50.f) <= ene[k].getShape().getPosition().y && (ene[k].getShape().getPosition().x - 50.f) <= bullets[i].getShape().getPosition().x && (ene[k].getShape().getPosition().x + 50.f) >= bullets[i].getShape().getPosition().x) {
                return (i);
            }
        }
    }
    return (-1);
}

void run(void)
{
    srand(time(NULL));
    std::string id;
    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket{io_context};
    sf::RenderWindow window(sf::VideoMode(800, 600), "R-TYPE", sf::Style::Default);
    sf::Music music;
    music.openFromFile("../battle.ogg");
    music.setVolume(50);
    sf::Music sound;
    sound.openFromFile("../laser.ogg");
    sound.setVolume(50);
    sf::Texture texture;
    texture.loadFromFile("../1.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Sprite sprite2;
    sprite2.setTexture(texture);
    sprite2.setPosition(sf::Vector2f(800, 0));
    std::vector<player> players;
    player p1;
    p1.setColor(sf::Color::Blue);
    p1.setSize(25.f);
    std::vector<player> bullets;
    player bullet;
    bullet.setColor(sf::Color::Red);
    bullet.setSize(12.f);
    int test = 0;
    for (int i = 0; i <= 3; i++) {
        bullets.push_back(player(bullet));
    }
    std::vector<ennemies> ene;
    ennemies ene1;
    ene1.setColor(sf::Color::Transparent);
    ene1.setSize(40.f);
    ene1.setSprite();
    ennemies ene2;
    ene2.setColor(sf::Color::Transparent);
    ene2.setSize(40.f);
    ene2.setSprite2();
    char recv_buf[1024];
    size_t len = 0;
    std::vector<std::string> floatss;
    for (int i = 0; i <= 3; i++) {
        players.push_back(player(p1));
    }
    for (int i = 0; i <= 19; i++) {
        if (i == 4 || i == 9 || i == 14 || i == 19)
            ene.push_back(ennemies(ene2));
        else
            ene.push_back(ennemies(ene1));
    }
    window.setFramerateLimit(60);
    socket.open(boost::asio::ip::udp::v4());
    socket.send_to(boost::asio::buffer("connection"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
    boost::asio::ip::udp::endpoint sender_endpoint;
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    	len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
        id = get_id(recv_buf);
        if (stoi(id) == 0 && test == 0) {
            music.play();
            test = 1;
        }
        floatss = parse_info(recv_buf, players);
        int boucle = 0;
        for (int n = 0; n < 4;n++, boucle = boucle + 2) {
            players[n].setPosX(std::stof(floatss[boucle]));
            players[n].setPosY(std::stof(floatss[boucle + 1]));
        }
        for (int n = 0; n < 20;n++, boucle = boucle + 2) {
            ene[n].setPosX(std::stof(floatss[boucle]));
            ene[n].setPosY(std::stof(floatss[boucle + 1]));
        }
        for (int n = 0; n < 4;n++, boucle = boucle + 2) {
            bullets[n].setPosX(std::stof(floatss[boucle]));
            bullets[n].setPosY(std::stof(floatss[boucle + 1]));
        }
        int col = check_collision_enemy(bullets, ene);
        int col_player = check_collision_players(players, ene);
        if (col != -1)
            socket.send_to(boost::asio::buffer("kill_ennemy" + std::to_string(col)), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (col_player != -1)
            socket.send_to(boost::asio::buffer("kill_player" + std::to_string(col_player)), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && window.hasFocus() == true)
            socket.send_to(boost::asio::buffer(id + " moveLeft"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && window.hasFocus() == true)
            socket.send_to(boost::asio::buffer(id +" moveRight"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && window.hasFocus() == true)
            socket.send_to(boost::asio::buffer(id +" moveAhead"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && window.hasFocus() == true)
            socket.send_to(boost::asio::buffer(id + " moveBehind"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus() == true) {
            sound.play();
            socket.send_to(boost::asio::buffer(id + " shoot"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        } else
            socket.send_to(boost::asio::buffer("u"), boost::asio::ip::udp::endpoint{boost::asio::ip::make_address("127.0.0.1"), 13});
        sprite.move(-10.f, 0.f);
        sprite2.move(-10.f, 0.f);
        if (sprite.getPosition().x <= -800)
            sprite.setPosition(sf::Vector2f(800, 0));
        if (sprite2.getPosition().x <= -800)
            sprite2.setPosition(sf::Vector2f(800, 0));
        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        for (size_t i = 0; i < players.size(); i++) {
            window.draw(players[i].getShape());
        }
        for (size_t i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].getShape());
        }
        for (size_t i = 0; i < ene.size(); i++)
            window.draw(ene[i].getShape());
        for (int i = 0; i <= 19; i++) {
            window.draw(ene[i].sprite);
        }
        window.display();
        memset(recv_buf, 0, 1024);
    }
}