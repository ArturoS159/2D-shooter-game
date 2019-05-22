#pragma once
#include <SFML/Graphics.hpp>
#include "GameSettings.h"

using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	void move(sf::Vector2f dir);
	int getX();
	int getY();
	int getSizeX();
	int getSizeY();
	void draw(sf::RenderWindow &window);
	void checkColisionWall();
	sf::Vector2f getDir();
	void setHp(int hp);
	int getHp();

private:
	int hp;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f dir;
};

