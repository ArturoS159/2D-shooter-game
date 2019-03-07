#pragma once
#include <string>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_COLOR 32
#define GAME_NAME "Test"

using namespace std;
class Game
{
public:
	unsigned int width = 800;
	unsigned int height = 600;
	unsigned int bitsPerPixel = 32;
	string nameGame = "Test";
	Game();
	~Game();
};

