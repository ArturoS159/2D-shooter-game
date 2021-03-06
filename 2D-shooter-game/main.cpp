#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameSettings.h"
#include "Menu.h"
#include "FinalMenu.h"
#include "Player.h"
#include "Bullet.h"
#include "Spider.h"
#include "SoundManager.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window{{SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_COLOR}, GAME_NAME, Style::Default};
	Menu menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	window.setFramerateLimit(FPS);
	Event windowEvent;
	SoundManager soundManager;

	Texture textureMenu;
	if (!textureMenu.loadFromFile("Images/back.png"))
	{
		return -1;
	}
	Sprite menuBackground;
	menuBackground.setTexture(textureMenu);

	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return -1;
	}
	window.setIcon(64, 64, icon.getPixelsPtr());

	Texture textureGrass;
	if (!textureGrass.loadFromFile("Images/grass.png"))
	{
		return -1;
	}

	Sprite gameBackground;
	gameBackground.setTexture(textureGrass);


	int k = 0;
	//MENU
	while (window.isOpen() && k == 0)
	{
		window.clear();
		window.draw(menuBackground);
		window.draw(menu);
		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case Event::KeyReleased:
				switch (windowEvent.key.code)
				{
				case Keyboard::Up:
					soundManager.play("menu.ogg");
					menu.MoveUp();
					break;

				case Keyboard::Down:
					soundManager.play("menu.ogg");
					menu.MoveDown();
					break;

				case Keyboard::Return:
					soundManager.play("click.ogg");
					switch (menu.getSelectetIndex())
					{
					case 1:
						k = 1;
						break;
					case 2:
						k = 2;
						break;
					case 3:
						k = 3;
						break;
					case 4:
						window.close();
						break;
					}
					break;
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
		}
		window.display();
	}
	//GRA SINGLE
	int pkt = 0;
	if (k == 1)
	{
		int spidersOnMap = 1;
		int lvl = 1;
		Player player;

		bool isFiring = false;
		vector<Bullet> bulletsList;
		vector<Spider> spiderList;

		Spider spider[50];
		spiderList.push_back(spider[0]);


		Font font;
		font.loadFromFile("Fonts/arial.ttf");
		Text pktText;
		pktText.setFont(font);
		pktText.setCharacterSize(20);
		pktText.setFillColor(Color::White);

		Text hpText;
		hpText.setFont(font);
		hpText.setCharacterSize(20);
		hpText.setFillColor(Color::White);
		hpText.setPosition(0, SCREEN_HEIGHT - hpText.getCharacterSize());

		Music backgroundMusic;
		backgroundMusic.openFromFile("Sounds/backgroundsound.ogg");
		backgroundMusic.setLoop(true);
		backgroundMusic.play();
		while (window.isOpen())
		{
			window.clear();
			window.draw(gameBackground);
			pktText.setString("PKT: " + to_string(pkt) + " Lvl: " + to_string(lvl) + " Spiders: " + to_string(spidersOnMap));
			hpText.setString("HP: " + to_string(player.getHp()) + " %");
			window.draw(pktText);
			window.draw(hpText);
			while (window.pollEvent(windowEvent))
			{
				if (windowEvent.type == Event::Closed)
				{
					window.close();
					break;
				}
				if (windowEvent.type == Event::KeyReleased)
				{
					if (windowEvent.key.code == Keyboard::Space)
					{
						isFiring = true;
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				player.move(Vector2f(0, -PLAYER_SPEED));
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				player.move(Vector2f(0, PLAYER_SPEED));
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				player.move(Vector2f(-PLAYER_SPEED, 0));
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				player.move(Vector2f(PLAYER_SPEED, 0));
			}

			if (isFiring == true)
			{
				if (bulletsList.size() < 5)
				{
					soundManager.play("bullet.ogg");
					Bullet newBullet(Vector2f(player.getX(), player.getY()), player);
					bulletsList.push_back(newBullet);
					isFiring = false;
				}
			}

			for (int i = 0; i < bulletsList.size(); i++)
			{
				bulletsList[i].draw(window);
				bulletsList[i].fire(player);
				if (bulletsList[i].checkColisionWall())
				{
					bulletsList.erase(bulletsList.begin() + i);
				}
			}
			if (player.getHp()<=0)
			{
				k = 2;
				break;
				
			}

			for (int i = 0; i < spiderList.size(); i++)
			{
				spiderList[i].draw(window);
				spiderList[i].doIt(player);
				int k = spiderList[i].checkColision(bulletsList);
				if (k != -1)
				{
					soundManager.play("spiderdeath.ogg");
					spiderList.erase(spiderList.begin() + i);
					bulletsList.erase(bulletsList.begin() + k);
					pkt++;
					spidersOnMap--;
					if (spidersOnMap == 0)
					{
						lvl++;
						unsigned n = lvl;
						spiderList.clear();

						if (n > 50)
						{
							window.close();
						}
						else
						{
							for (unsigned i = 0; i < n; i++)
							{
								spiderList.push_back(spider[i]);
							}
							spidersOnMap = spiderList.size();
						}
					}
				}
			}
			player.checkColisionWall();
			player.draw(window);
			window.display();
		}
	}
	if (k == 2) {
		FinalMenu menuF(SCREEN_WIDTH, SCREEN_HEIGHT,pkt);
		while (window.isOpen())
		{
			window.clear();
			window.draw(menuBackground);
			window.draw(menuF);
			while (window.pollEvent(windowEvent))
			{
				switch (windowEvent.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Keyboard::Return:
					window.close();
					break;
				}
			}
			window.display();
		}
	}
	
}
