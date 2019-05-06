#pragma once
#include <SFML/Graphics.hpp>
#include "GameSettings.h"

using namespace sf;
using namespace std;

class Player : public Drawable
{
public:
	Player();
	Player(float x, float y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setCords(float x, float y);
	string getCordinates();
private:
	CircleShape player;
	virtual void draw(RenderTarget& target, RenderStates states)const;
};

