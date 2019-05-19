#pragma once
#include <SFML/Graphics.hpp>
class Spider
{
public:
	Spider();
	~Spider();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

