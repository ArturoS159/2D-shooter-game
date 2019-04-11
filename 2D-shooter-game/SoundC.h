#pragma once
#include <SFML/Audio.hpp>
#include <string>

using namespace std;

class SoundC
{
public:
	SoundC();
	void play(string musicName);
private:
	sf::Music sound;
};

