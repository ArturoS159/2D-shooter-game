#pragma once
#include "Player.h"

class Ai
{
public:
	Ai();
	void doIt(Player &computer, Player &player);
private:
	Player player;
	Player computer;
};

