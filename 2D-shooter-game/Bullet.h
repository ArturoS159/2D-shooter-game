#pragma once
#include <SFML/Graphics.hpp>

class Player;
using namespace sf;

class Bullet
{
public:
	Bullet(Vector2f pos, Player player);
	~Bullet();
	void fire(Player player);
	void draw(RenderWindow& window);
	bool checkColisionWall();
	int getX();
	int getY();
private:
	Vector2f dir;
	CircleShape bullet;
};
