#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace std;
using namespace sf;
int main()
{
	Game game;
	RenderWindow window{ {SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_COLOR}, GAME_NAME };

	while (window.isOpen()) {
		Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			if (windowEvent.type == Event::Closed)
				window.close();
		}
		window.display();
	}
}
