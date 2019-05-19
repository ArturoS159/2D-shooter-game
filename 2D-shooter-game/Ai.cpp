#include "pch.h"
#include "Ai.h"
#include <iostream>


Ai::Ai(){

}

void Ai::doIt(Player &computer, Player &player)
{
	computer.move(sf::Vector2f(100,5));
}


