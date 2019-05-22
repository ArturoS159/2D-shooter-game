#include "pch.h"
#include "Spider.h"
#include <iostream>
#include "SoundManager.h"
#include <random>

Spider::Spider()
{
	this->texture.loadFromFile("Images/spider.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);

	random_device rd;
	mt19937 mt(rd());
	const uniform_real_distribution<float> rand(100, 500);
	this->sprite.setPosition(rand(mt), rand(mt));
}
SoundManager soundManager;
void Spider::doIt(Player& player)
{
	
	if (player.getX()-player.getSizeX() / 2 > sprite.getPosition().x) {
		move(sf::Vector2f(SPIDER_SPEED,0));
	}
	if (player.getX() + player.getSizeX() / 2 < sprite.getPosition().x) {
		move(sf::Vector2f(-SPIDER_SPEED, 0));
	}
	if (player.getY() - player.getSizeY() / 2 > sprite.getPosition().y) {
		move(sf::Vector2f(0, SPIDER_SPEED));
	}
	if (player.getY() + player.getSizeY() / 2 < sprite.getPosition().y) {
		move(sf::Vector2f(0, -SPIDER_SPEED));
	}
	if (player.getX() - sprite.getPosition().x <= player.getSizeX()/2 && player.getX() - sprite.getPosition().x >= -player.getSizeX()/2) {
		if (player.getY() - sprite.getPosition().y <= player.getSizeY() / 2 && player.getY() - sprite.getPosition().y >= -player.getSizeY() / 2) {
			if (attacked) {
				attack(player);
				soundManager.play("spiderattack.ogg");
				attacked = false;
			}
		}
	}
}

void Spider::move(sf::Vector2f dir)
{
	if (dir.x >= 0 && dir.y == 0) {
		this->sprite.setRotation(270);
		this->sprite.move(dir);
		attacked = true;
	}
	else if (dir.x <= 0 && dir.y == 0) {
		this->sprite.setRotation(90);
		this->sprite.move(dir);
		attacked = true;
	}
	else if (dir.x == 0 && dir.y <= 0) {
		this->sprite.setRotation(180);
		this->sprite.move(dir);
		attacked = true;
	}
	else if (dir.x == 0 && dir.y >= 0) {
		this->sprite.setRotation(0);
		this->sprite.move(dir);
		attacked = true;
	}
	
}

void Spider::attack(Player &player)
{
	player.setHp(player.getHp()- SPIDER_POWER);
}

void Spider::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

int Spider::checkColision(vector<Bullet> bulletsList)
{
	for (int i = 0; i < bulletsList.size(); i++) {
		if (bulletsList[i].getX()>=sprite.getPosition().x - texture.getSize().x / 2 && bulletsList[i].getX() <= sprite.getPosition().x + texture.getSize().x / 2) {
			if (bulletsList[i].getY() >= sprite.getPosition().y - texture.getSize().y / 2 && bulletsList[i].getY() <= sprite.getPosition().y + texture.getSize().y / 2) {
				return i;
				
			}
			return -1;
		}
		
	}
	return -1;
}