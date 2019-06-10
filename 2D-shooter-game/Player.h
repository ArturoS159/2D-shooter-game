#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player
{
public:
	Player();
	void move(Vector2f dir);
	int getX();
	int getY();
	int getSizeX();
	int getSizeY();
	void draw(RenderWindow& window);
	void checkColisionWall();
	Vector2f getDir();
	void setHp(int hp);
	int getHp();

private:
	int hp;
	Texture texture;
	Sprite sprite;
	Vector2f dir;
};
