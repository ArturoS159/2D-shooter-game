#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

class Spider
{
public:
	Spider();
	void doIt(Player& player);
	void draw(RenderWindow& window);
	int checkColision(vector<Bullet> bulletsList);
private:
	Texture texture;
	Sprite sprite;
	void move(Vector2f dir);
	void attack(Player& player);
	bool attacked{};
};
