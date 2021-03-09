#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cmath>
#include <unordered_map>

#include "Tile.h"

/*

content is considered the "central operation" of the game. Everything meets up here.

*/

class content
{
public:
	std::unordered_map<tileID, Tile> TileSet;

	content();

	void init(SDL_Renderer* g);

	void loadTileSet(SDL_Renderer* g);

	void Update();

	void Render(SDL_Renderer* g, SDL_Surface* buffer);

	~content();
};