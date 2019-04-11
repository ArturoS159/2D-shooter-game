#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Menu.h"
#include "SoundC.h"
using namespace std;
using namespace sf;
int main()
{
	Game game;
	RenderWindow window{ {SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_COLOR}, GAME_NAME ,Style::Close};
	Menu menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	window.setFramerateLimit(FPS);
	Event windowEvent;
	SoundC sound;


	Texture texture;
	if (!texture.loadFromFile("Images/back.png"))
		return -1;
	Sprite sprite;
	sprite.setTexture(texture);

	Image icon;
	if (!icon.loadFromFile("Images/icon.png")) {
		return -1;
	}
	window.setIcon(64, 64, icon.getPixelsPtr());
	

	while (window.isOpen()) {
		window.clear();
		window.draw(sprite);
		window.draw(menu);
		while (window.pollEvent(windowEvent)) {
			switch (windowEvent.type)
			{
			case Event::KeyReleased:
				switch (windowEvent.key.code)
				{
				case Keyboard::Up:
					sound.play("menu.ogg");
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					sound.play("menu.ogg");
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					sound.play("click.ogg");
					switch(menu.getSelectetIndex())
					{
					case 1:
						std::cout << "PLAY" << std::endl;
						break;
					case 2:
						std::cout << "HOST" << std::endl;
						break;
					case 3:
						std::cout << "JOIN" << std::endl;
						break;
					case 4:
						window.close();
						break;
					}
					break;
				}

				break;
			case sf::Event::Closed:
				window.close();
				break;

			}
		}
		
		window.display();
	}

}
