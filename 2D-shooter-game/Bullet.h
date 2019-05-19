#pragma once
#include <SFML/Graphics.hpp>

class Player;
using namespace sf;

class Bullet
{
public:
	Bullet(sf::Vector2f pos, Player player);
	~Bullet();
	void fire(Player player);
	void draw(sf::RenderWindow &window);
	bool checkColisionWall();
	
private:
	sf::Vector2f dir;
	sf::CircleShape bullet;
};

