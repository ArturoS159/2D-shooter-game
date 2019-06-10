#pragma once
#define MENU_NUMBERS 3
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;


class Menu : public Drawable
{
public:
	Menu(float width, float height);
	void MoveUp();
	void MoveDown();
	int getSelectetIndex();
private:
	Text menu[MENU_NUMBERS];
	Font font;
	int selectedIndex = 1;
	void draw(RenderTarget& target, RenderStates states) const override;
};
