/*
** EPITECH PROJECT, 2020
** r-type
** File description:
** main
*/

#include <ctime>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/asio.hpp>
#include "include/client.hpp"
#include "include/player.hpp"
#include "include/ennemy.hpp"
boost::asio::io_context io_context;

/*player *pl0 = new player();
player *pl1 = new player();
player *pl2 = new player();
player *pl3 = new player();*/
std::vector<player> pl;
std::vector<cclient> lclient;
std::vector<ennemy> en;
int nbclient = 0;
int nbennem = 0;

void client_connection(boost::asio::ip::udp::endpoint client)
{
	if (nbclient < 4) {
		std::cout << client << " connected." << '\n';
			lclient[nbclient].endpoint = client;
			lclient[nbclient].setused(1);
			pl[nbclient].setx(10);
			pl[nbclient].sety(10);
		nbclient++;
	}
}

void handle_movement(char *msg)
{
	std::string move = msg;
	int id = msg[0] - '0';
	if (move.find("kill_ennemy") == 0) {
		move.erase(0, 11);
		id = std::stoi(move);
		en[id].kill_ennemy();
	} else if (move.find("kill_player") == 0) {
		move.erase(0, 11);
		id = std::stoi(move);
		std::cout << id << std::endl;
		pl[id].kill_player();
	} else
		move.erase(0, 2);
	if (move.find("moveLeft") == 0)
		pl[0].setx(pl[0].getx() - 10);
	if (move.find("moveRight") == 0)
		pl[id].setx(pl[id].getx() + 10);
	if (move.find("moveAhead") == 0)
		pl[id].sety(pl[id].gety() - 10);
	if (move.find("moveBehind") == 0)
		pl[id].sety(pl[id].gety() + 10);
	if (move.find("shoot") == 0)
		if (pl[id].getisshooted() == false)
			pl[id].shoot();
}

void handle_message(boost::asio::ip::udp::endpoint client, char *msg)
{
	int x = 0;
	if (strncmp(msg, "connection", 10) == 0) {
		client_connection(client);
	} else {
		handle_movement(msg);
	}
}

void set_player()
{
	lclient.push_back(cclient());
	lclient.push_back(cclient());
	lclient.push_back(cclient());
	lclient.push_back(cclient());
	pl.push_back(player());
	pl.push_back(player());
	pl.push_back(player());
	pl.push_back(player());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
	en.push_back(ennemy());
}

int algo_ennem(int y)
{
	int x = 0;
	if (nbennem < 20 && y >= 20) {
		for (; en[x].getused2() != false; x++);
		en[x].create_ennemy();
		y = 0;
	}
	x = 0;
	while (x < 20) {
		if (en[x].getused2() == true)
			if (x == 4 || x == 9 || x == 14 || x == 19)
				en[x].setx2(en[x].getx2() - 6);
			else
				en[x].setx2(en[x].getx2() - 3);
		if (en[x].getx2() < -50)
			en[x].kill_ennemy();
		x++;
	}
	if (pl[0].getisshooted() == true)
		pl[0].setbx(pl[0].getbx() + 5);
	if (pl[1].getisshooted() == true)
		pl[1].setbx(pl[1].getbx() + 5);
	if (pl[2].getisshooted() == true)
		pl[2].setbx(pl[2].getbx() + 5);
	if (pl[3].getisshooted() == true)
		pl[3].setbx(pl[3].getbx() + 5);
	if (pl[0].getbx() > 850)
		pl[0].destroy_shoot();
	if (pl[1].getbx() > 850)
		pl[1].destroy_shoot();
	if (pl[2].getbx() > 850)
		pl[2].destroy_shoot();
	if (pl[3].getbx() > 850)
		pl[3].destroy_shoot();
	return y;
}

std::string getinfo()
{
	std::string temp;
	temp = "0/";
	for (int x = 0; x < 4; x++)
		temp.append(std::to_string(pl[x].getx()) + "/" + std::to_string(pl[x].gety()) + "/");
	for (int x = 0; x < 20; x++)
		temp.append(std::to_string(en[x].getx2()) + "/" + std::to_string(en[x].gety2()) + "/");
	for (int x = 0; x < 4; x++)
		temp.append(std::to_string(pl[x].getbx()) + "/" + std::to_string(pl[x].getby()) + "/");
	temp.append("\0");
	return (temp);
}

void boucle()
{
	srand(time(NULL));
	int x = 0;
	int y = 0;
	std::string info;
	set_player();
	try {
		boost::asio::ip::udp::socket socket(io_context, boost::asio::ip::udp::endpoint{boost::asio::ip::udp::v4(), 13});
		char msg[1024];
		while (1) {
			if (x == nbclient)
				x = 0;
			boost::asio::ip::udp::endpoint client;
			socket.receive_from(boost::asio::buffer(msg), client);
			handle_message(client, msg);
			y = algo_ennem(y);
			info.resize(0);
			info = getinfo();
			if (lclient[0].getused() == 1 && x == 0)
				socket.send_to(boost::asio::buffer(info), lclient[0].endpoint);
			info[0] = '1';
			if (lclient[1].getused() == 1 && x == 1)
				socket.send_to(boost::asio::buffer(info), lclient[1].endpoint);
			info[0] = '2';
			if (lclient[2].getused() == 1 && x == 2)
				socket.send_to(boost::asio::buffer(info), lclient[2].endpoint);
			info[0] = '3';
			if (lclient[3].getused() == 1 && x == 3)
				socket.send_to(boost::asio::buffer(info), lclient[3].endpoint);
			memset(msg, 0, 1024);
			x++;
			y++;
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	boucle();
	return 0;
}

ennemy::ennemy()
{
	this->x = -100;
	this->y = -100;
	this->used = false;
}

ennemy::~ennemy()
{
}

void ennemy::create_ennemy()
{
	this->x = 800;
	this->y = rand() % 600;
	this->used = true;
	nbennem++;
}

void ennemy::kill_ennemy()
{
	this->x = 1000;
	this->y = 1000;
	this->used = false;
	nbennem--;
}