#include "pch.h"
#include "SoundManager.h"


void SoundManager::play(string musicName)
{
	music.openFromFile("Sounds/" + musicName);
	music.play();
}
