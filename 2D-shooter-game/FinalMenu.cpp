#include "pch.h"
#include "FinalMenu.h"
#include <iostream>
#include "GameSettings.h"

FinalMenu::FinalMenu(float width, float height,int pkt)
{
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		cout << "ERROR";
	}
	cout << pkt;
	menu.setFont(font);
	menu.setCharacterSize(50);
	menu.setString("Twoje punkty: " +to_string(pkt));
	menu.setFillColor(Color::Blue);
	menu.setPosition(Vector2f(width / 2 - menu.getLocalBounds().width / 2, 70));
}

void FinalMenu::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(this->menu, states);
}