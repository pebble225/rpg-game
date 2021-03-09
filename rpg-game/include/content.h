#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cmath>

#include "Tile.h"

/*

content is considered the "central operation" of the game. Everything meets up here.

*/

class content
{
public:
	Tile* TileSet[0x10000];

	content();

	void init(SDL_Renderer* g);

	void loadTileSet(SDL_Renderer* g);

	void Update();

	void Render(SDL_Renderer* g, SDL_Surface* buffer);

	~content();
};