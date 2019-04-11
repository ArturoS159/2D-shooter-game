#include "pch.h"
#include "SoundC.h"

SoundC::SoundC()
{
}

void SoundC::play(string musicName)
{
	sound.openFromFile("Sounds/"+musicName);
	sound.play();
}
