#include "pch.h"
#include "Bullet.h"
#include "Player.h"
#include <iostream>


Bullet::Bullet(sf::Vector2f pos,Player player)
{
	this->bullet.setRadius(5);
	this->bullet.setFillColor(Color::Blue);
	this->bullet.setPosition(pos);
	this->dir = player.getDir();
}


Bullet::~Bullet()
{
}

void Bullet::fire(Player player)
{
	this->bullet.move(this->dir);
}

void Bullet::draw(sf::RenderWindow & window)
{
	window.draw(this->bullet);
}

bool Bullet::checkColisionWall()
{
	if (bullet.getPosition().x > SCREEN_WIDTH) {
		return true;
	}else if (bullet.getPosition().x < 0) {
		return true;
	}
	if (bullet.getPosition().y > SCREEN_HEIGHT) {
		return true;
	}else if (bullet.getPosition().y < 0) {
		return true;
	}
	return false;
}