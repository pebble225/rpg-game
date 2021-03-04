#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <sstream>

#include "Tile.h"

/*

content is considered the "central operation" of the game. Everything meets up here.

*/

class content
{
public:
	std::vector<Tile> tileSet;

	content();

	void init();

	void loadTileSet();

	~content();
};