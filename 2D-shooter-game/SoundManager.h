#pragma once
#include <SFML/Audio.hpp>
#include <string>

using namespace std;

class SoundManager
{
public:
	void play(string musicName);
private:
	sf::Music music;
};
