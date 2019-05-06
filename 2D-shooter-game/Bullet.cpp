#include "pch.h"
#include "Bullet.h"
#include "Player.h"


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
