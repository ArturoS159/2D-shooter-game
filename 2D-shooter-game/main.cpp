#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameSettings.h"
#include "Menu.h"
#include "SoundC.h"
#include "Player.h"
using namespace std;
using namespace sf;
int main()
{
	RenderWindow window{ {SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_COLOR}, GAME_NAME ,Style::Close};
	Menu menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	window.setFramerateLimit(FPS);
	Event windowEvent;
	SoundC sound;

	Texture texture;
	if (!texture.loadFromFile("Images/back.png")) {
		return -1;
	}
		
	Sprite background;
	background.setTexture(texture);

	Image icon;
	if (!icon.loadFromFile("Images/icon.png")) {
		return -1;
	}
	window.setIcon(64, 64, icon.getPixelsPtr());
	

	int k = 0;
	//MENU
	while (window.isOpen()&&k==0){
		window.clear();
		window.draw(background);
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
						k = 1;
						break;
					case 2:
						k = 2;
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
	Player player;
	//GRA
	while (window.isOpen() && k == 1) {
		window.clear();
		window.draw(player);
		while (window.pollEvent(windowEvent)) {
			if (windowEvent.type == Event::Closed) {
				window.close();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player.moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			player.moveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.moveRight();
		}
		window.display();
	}

}
