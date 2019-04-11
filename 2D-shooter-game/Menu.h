#pragma once
#define MENU_NUMBERS 5
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;


class Menu: public sf::Drawable
{
public:
	Menu(float width, float height);
	void MoveUp();
	void MoveDown();
	int getSelectetIndex();
private:
	Text menu[5];
	Font font;
	int selectedIndex=1;
	virtual void draw(RenderTarget& target, RenderStates states)const;
};
