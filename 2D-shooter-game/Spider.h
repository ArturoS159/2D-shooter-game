#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
class Spider
{
public:
	Spider();
	void doIt(Player &player);
	void draw(sf::RenderWindow& window);
	int checkColision(vector <Bullet> bulletsList);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void move(sf::Vector2f dir);
	void attack(Player& player);
	bool attacked;

};

