#include "SFML/Graphics.hpp"
#pragma once
class Stone
{
public:
	Stone(sf::Vector2f pos);
	~Stone();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

