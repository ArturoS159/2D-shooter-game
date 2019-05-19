#include "pch.h"
#include "Stone.h"
#include <iostream>


Stone::Stone(sf::Vector2f pos)
{
	this->texture.loadFromFile("Images/stone.png");
	this->sprite.setTexture(texture);
	sprite.setPosition(pos);
}

void Stone::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

Stone::~Stone()
{
}
