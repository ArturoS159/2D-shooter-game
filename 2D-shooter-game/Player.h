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
	void draw(sf::RenderWindow &window);
	sf::Vector2f getDir();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f dir;
};

