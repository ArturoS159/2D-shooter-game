#pragma once
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;


class FinalMenu : public Drawable
{
public:
	FinalMenu(float width, float height,int pkt);
private:
	Text menu;
	Font font;
	void draw(RenderTarget& target, RenderStates states) const override;
};
