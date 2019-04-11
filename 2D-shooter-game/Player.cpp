#include "pch.h"
#include "Player.h"


Player::Player(){
	player.setRadius(30);
	player.setOrigin(30 / 2, 30 / 2);
	player.setPosition(300, 300);
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
