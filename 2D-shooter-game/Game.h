#pragma once
#include <string>
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

