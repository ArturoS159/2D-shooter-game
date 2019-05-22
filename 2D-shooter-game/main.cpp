#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "GameSettings.h"
#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "Spider.h"
#include "SoundManager.h"

using namespace std;
using namespace sf;
int main()
{
	RenderWindow window{ {SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_COLOR}, GAME_NAME ,Style::Default };
	Menu menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	window.setFramerateLimit(FPS);
	Event windowEvent;
	SoundManager soundManager;

	Texture textureMenu;
	if (!textureMenu.loadFromFile("Images/back.png")) {
		return -1;
	}
	Sprite menuBackground;
	menuBackground.setTexture(textureMenu);

	Image icon;
	if (!icon.loadFromFile("Images/icon.png")) {
		return -1;
	}
	window.setIcon(64, 64, icon.getPixelsPtr());

	Texture textureGrass;
	if (!textureGrass.loadFromFile("Images/grass.png")) {
		return -1;
	}

	Sprite gameBackground;
	gameBackground.setTexture(textureGrass);




	int k = 0;
	//MENU
	while (window.isOpen() && k == 0) {
		window.clear();
		window.draw(menuBackground);
		window.draw(menu);
		while (window.pollEvent(windowEvent)) {
			switch (windowEvent.type)
			{
			case Event::KeyReleased:
				switch (windowEvent.key.code)
				{
				case Keyboard::Up:
					soundManager.play("menu.ogg");
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					soundManager.play("menu.ogg");
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
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
			case sf::Event::Closed:
				window.close();
				break;

			}
		}
		window.display();
	}
	//GRA SINGLE
	if(k==1)
	{
		int spidersOnMap = 1;
		int pkt = 0;
		Player player;
		bool isFiring = false;
		vector<Bullet> bulletsList;
		vector<Spider> spiderList;

		//TODO zamiana vectora na liste
		//TODO jezeli liczba pajaczkow = 0 to generowanie pajaczkow zmienna spider on map trzeba zwiekszac gdy liczba pajakow = 0 i tyle ma byc pajaczkow czyli 1 2 3 4 ... n

		Spider spider;
		spiderList.push_back(spider);
		
		
		Font font;
		font.loadFromFile("Fonts/arial.ttf");
		Text pktText;
		pktText.setFont(font);
		pktText.setCharacterSize(20);
		pktText.setFillColor(sf::Color::White);

		Text hpText;
		hpText.setFont(font);
		hpText.setCharacterSize(20);
		hpText.setFillColor(sf::Color::White);
		hpText.setPosition(0, SCREEN_HEIGHT-hpText.getCharacterSize());

		Music backgroundMusic;
		backgroundMusic.openFromFile("Sounds/backgroundsound.ogg");
		backgroundMusic.setLoop(true);
		backgroundMusic.play();
		while (window.isOpen()) {
			
			window.clear();
			window.draw(gameBackground);
			pktText.setString("PKT: " + to_string(pkt));
			
			hpText.setString("HP: " + to_string(player.getHp()) + " %");
			window.draw(pktText);
			window.draw(hpText);
			while (window.pollEvent(windowEvent)) {
				if (windowEvent.type == Event::Closed) {
					window.close();
					break;
				}
				if (windowEvent.type == Event::KeyReleased) {
					if (windowEvent.key.code == sf::Keyboard::Space) {
						isFiring = true;
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				player.move(sf::Vector2f(0, -PLAYER_SPEED));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player.move(sf::Vector2f(0, PLAYER_SPEED));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player.move(sf::Vector2f(-PLAYER_SPEED, 0));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player.move(sf::Vector2f(PLAYER_SPEED, 0));
			}

			if (isFiring == true) {
				if (bulletsList.size() < 5) {
					soundManager.play("bullet.ogg");
					Bullet newBullet(sf::Vector2f(player.getX(), player.getY()), player);
					bulletsList.push_back(newBullet);
					isFiring = false;
				}
			}

			for (int i = 0; i < bulletsList.size(); i++) {
				bulletsList[i].draw(window);
				bulletsList[i].fire(player);
				if (bulletsList[i].checkColisionWall()) {
					bulletsList.erase(bulletsList.begin() + i);
				}
			}

			for (int i = 0; i < spiderList.size(); i++) {
				spiderList[i].draw(window);
				spiderList[i].doIt(player);
				int k = spiderList[i].checkColision(bulletsList);
				if (k!=-1) {
					soundManager.play("spiderdeath.ogg");
					spiderList.erase(spiderList.begin() + i);
					bulletsList.erase(bulletsList.begin() + k);
					pkt++;
				}
			}
			player.checkColisionWall();
			player.draw(window);
			window.display();
		}
	}
	///////////////////

	///////Gra Multi HOST
	//if (k == 2) {
	//	sf::TcpListener listener;
	//	unsigned int port = 54000;

	//	if (listener.listen(port) != sf::Socket::Done)
	//	{
	//		cerr << "Nie mogę rozpocząć nasłuchiwania na porcie " << port << endl;
	//		exit(1);
	//	}
	//	sf::TcpSocket socket;
	//	listener.accept(socket);
	//	Player myPlayer;
	//	Player enemyPlayer;

	//	string playerEnemyCord = enemyPlayer.getCordinates();
	//	string playerHostCord = myPlayer.getCordinates();

	//	socket.send(playerEnemyCord.c_str(), playerEnemyCord.size() + 1);
	//	socket.send(playerHostCord.c_str(), playerHostCord.size() + 1);

	//	while (window.isOpen()) {
	//		window.clear();
	//		window.draw(myPlayer);
	//		window.draw(enemyPlayer);
	//		while (window.pollEvent(windowEvent)) {
	//			if (windowEvent.type == Event::Closed) {
	//				window.close();
	//				break;
	//			}
	//			
	//		}
	//		if (Keyboard::isKeyPressed(Keyboard::Up)) {
	//			myPlayer.moveUp();
	//			playerHostCord = myPlayer.getCordinates();
	//			socket.send(playerHostCord.c_str(), playerHostCord.size() + 1);
	//		}
	//		if (Keyboard::isKeyPressed(Keyboard::Down)) {
	//			myPlayer.moveDown();
	//		}
	//		if (Keyboard::isKeyPressed(Keyboard::Left)) {
	//			myPlayer.moveLeft();
	//		}
	//		if (Keyboard::isKeyPressed(Keyboard::Right)) {
	//			myPlayer.moveRight();
	//		}
	//		window.display();
	//	}
	//}

	///////////CLIENT
	//if (k == 3) {
	//	sf::TcpSocket socket;
	//	sf::IpAddress ip = "127.0.0.1";
	//	unsigned int port = 54000;

	//	if (socket.connect(ip, port) != sf::Socket::Done)
	//	{
	//		cerr << "Nie można połączyć się z " << ip.toString() << endl;
	//		exit(1);
	//	}
	//	char buffer[1024];
	//	size_t received = 0;
	//	socket.receive(buffer, sizeof(buffer), received);
	//	string s = buffer;
	//	Player myPlayer(atof(s.substr(0, s.find(',')).c_str()), atof(s.substr(s.find(',')+1, s.size()).c_str()));
	//	socket.receive(buffer, sizeof(buffer), received);
	//	s = buffer;
	//	Player enemyPlayer(atof(s.substr(0, s.find(',')).c_str()), atof(s.substr(s.find(',') + 1, s.size()).c_str()));


	//	while (window.isOpen()) {
	//		window.clear();
	//		window.draw(myPlayer);
	//		window.draw(enemyPlayer);
	//		while (window.pollEvent(windowEvent)) {
	//			if (windowEvent.type == Event::Closed) {
	//				window.close();
	//				break;
	//			}
	//			
	//		}
	//		socket.receive(buffer, sizeof(buffer), received);
	//		s = buffer;
	//		enemyPlayer.setCords(atof(s.substr(0, s.find(',')).c_str()), atof(s.substr(s.find(',') + 1, s.size()).c_str()));

	//		window.display();
	//	}
	//}
}