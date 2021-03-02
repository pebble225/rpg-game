#include "../include/imgdata.h"

#include <SDL.h>
#include <SDL_image.h>

/*

Severity	Code	Description	Project	File	Line	Suppression State
Error	C2129	static function 'void imgData::initialize(void)' declared but not defined	rpg-game
C:\Users\...\source\repos\rpg-game\rpg-game\src\main.cpp	110

*/

SDL_Surface* imgData::loadImage(const std::string dir)
{
	const char* dir_char = dir.c_str();

	SDL_Surface* s = IMG_Load(dir_char);

	return s;
}

void imgData::initialize()
{
	sampleSprite = loadImage(resDir + "img/sample.png");
}

void imgData::uninitialize()
{
	SDL_FreeSurface(sampleSprite);
}