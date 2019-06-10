#include "pch.h"
#include "Menu.h"
#include <iostream>
#include "GameSettings.h"

using namespace std;
using namespace sf;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		cout << "ERROR";
	}
	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setString(GAME_NAME);
	menu[0].setFillColor(Color::Blue);
	menu[0].setPosition(Vector2f(width / 2 - menu[0].getLocalBounds().width / 2, height / (MENU_NUMBERS + 1) * 0));

	menu[1].setFont(font);
	menu[1].setCharacterSize(35);
	menu[1].setString("PLAY SINGLE");
	menu[1].setFillColor(Color::Red);
	menu[1].setPosition(Vector2f(width / 2 - menu[1].getLocalBounds().width / 2, height / (MENU_NUMBERS + 1) * 1));

	menu[2].setFont(font);
	menu[2].setCharacterSize(35);
	menu[2].setString("EXIT");
	menu[2].setFillColor(Color::Black);
	menu[2].setPosition(Vector2f(width / 2 - menu[2].getLocalBounds().width / 2, height / (MENU_NUMBERS + 1) * 2));
}

void Menu::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->menu[0], states);
	target.draw(this->menu[1], states);
	target.draw(this->menu[2], states);
}

void Menu::MoveUp()
{
	if (selectedIndex - 1 >= 1)
	{
		menu[selectedIndex].setFillColor(Color::Black);
		selectedIndex--;
		menu[selectedIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedIndex + 1 < MENU_NUMBERS)
	{
		menu[selectedIndex].setFillColor(Color::Black);
		selectedIndex++;
		menu[selectedIndex].setFillColor(Color::Red);
	}
}

int Menu::getSelectetIndex()
{
	return selectedIndex;
}
