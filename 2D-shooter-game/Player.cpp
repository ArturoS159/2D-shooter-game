#include "pch.h"
#include "Player.h"
#include <random>
#include <iostream>
#include "GameSettings.h"

using namespace std;

Player::Player(){
	this->texture.loadFromFile("Images/soldier.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);

	random_device rd;
	mt19937 mt(rd());
	const uniform_real_distribution<float> rand(100, 500);
	this->sprite.setPosition(rand(mt), rand(mt));
	this->dir = sf::Vector2f(0, -BULLET_SPEED);
	this->hp = 100;
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void Player::checkColisionWall()
{
	if (sprite.getPosition().x+ texture.getSize().x/2 > SCREEN_WIDTH) {
		sprite.setPosition(sprite.getPosition().x - PLAYER_SPEED, sprite.getPosition().y);
		
	}else if (sprite.getPosition().x - texture.getSize().x / 2 < 0) {
		sprite.setPosition(sprite.getPosition().x + PLAYER_SPEED, sprite.getPosition().y);
	}
	if (sprite.getPosition().y + texture.getSize().y / 2 > SCREEN_HEIGHT) {
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - PLAYER_SPEED);
	}
	else if (sprite.getPosition().y - texture.getSize().y / 2 < 0) {
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + PLAYER_SPEED);
	}

}

void Player::move(sf::Vector2f dir) {
	if (dir.x >= 0 && dir.y == 0){
		this->sprite.setRotation(90);
		this->sprite.move(dir);
		this->dir = sf::Vector2f(BULLET_SPEED, 0);
	}else if (dir.x <= 0 && dir.y == 0){
		this->sprite.setRotation(270);
		this->sprite.move(dir);
		this->dir = sf::Vector2f(-BULLET_SPEED, 0);
	}else if (dir.x == 0 && dir.y <= 0){
		this->sprite.setRotation(0);
		this->sprite.move(dir);
		this->dir = sf::Vector2f(0, -BULLET_SPEED);
	}else if (dir.x == 0 && dir.y >= 0){
		this->sprite.setRotation(180);
		this->sprite.move(dir);
		this->dir = sf::Vector2f(0, BULLET_SPEED);
	}
}

int Player::getX()
{
	return this->sprite.getPosition().x;
}

int Player::getY()
{
	return this->sprite.getPosition().y;
}

int Player::getSizeX()
{
	return this->texture.getSize().x;
}
int Player::getSizeY()
{
	return this->texture.getSize().y;
}

sf::Vector2f Player::getDir(){
	return this->dir;
}

void Player::setHp(int hp)
{
	this->hp = hp;
}

int Player::getHp()
{
	return hp;
}
