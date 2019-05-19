#include "pch.h"
#include "Spider.h"


Spider::Spider()
{
	this->texture.loadFromFile("Images/soldier.png");
	this->sprite.setTexture(this->texture);
}


Spider::~Spider()
{
}

void Spider::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}