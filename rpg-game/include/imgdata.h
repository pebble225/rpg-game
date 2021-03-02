#pragma once

#include <iostream>
#include <string>

#include <SDL_image.h>

const std::string resDir = "../res/";

namespace imgData
{
	SDL_Surface* sampleSprite;

	static SDL_Surface* loadImage(const std::string dir);
	static void initialize();

	static void uninitialize();
}

/*

I would prefer not to make imgData into a class and carrying around an instance with all
of the loaded image data, but it's looking like I'm going to have to do that.

*/