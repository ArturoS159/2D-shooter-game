#include "pch.h"
#include "Player.h"
#include <random>

using namespace std;

Player::Player(){
	random_device rd;
	mt19937 mt(rd());
	const uniform_real_distribution<float> dist(100, 500);
	player.setRadius(30);
	player.setOrigin(30 / 2, 30 / 2);
	player.setPosition(dist(mt), dist(mt));
}
Player::Player(float x, float y) {
	player.setRadius(30);
	player.setOrigin(30 / 2, 30 / 2);
	player.setPosition(x, y);
}

void Player::draw(RenderTarget & target, RenderStates states) const{
	target.draw(this->player, states);
}

void Player::moveUp() {
	player.setPosition(player.getPosition().x, player.getPosition().y - PLAYER_SPEED);
}

void Player::moveDown() {
	player.setPosition(player.getPosition().x, player.getPosition().y + PLAYER_SPEED);
}

void Player::moveLeft() {
	player.setPosition(player.getPosition().x - PLAYER_SPEED, player.getPosition().y);
}

void Player::moveRight() {
	player.setPosition(player.getPosition().x + PLAYER_SPEED, player.getPosition().y);
}

void Player::setCords(float x, float y){
	player.setPosition(x, y);
}

string Player::getCordinates(){
	string txtReturn = "";
	txtReturn.append(to_string(player.getPosition().x));
	txtReturn.append(",");
	txtReturn.append(to_string(player.getPosition().y));
	return txtReturn;
}
