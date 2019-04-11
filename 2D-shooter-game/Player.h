#pragma once
#include <SFML/Graphics.hpp>
#include "GameSettings.h"

using namespace sf;

class Player : public Drawable
{
public:
	Player();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
private:
	CircleShape player;
	virtual void draw(RenderTarget& target, RenderStates states)const;
};

