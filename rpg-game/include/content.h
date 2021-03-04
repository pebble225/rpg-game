#pragma once
#include <vector>

#include "Tile.h"

/*

content is considered the "central operation" of the game. Everything meets up here.

*/

class content
{
public:
	std::vector<Tile> tileSet;

	content();

	void init();//just in case I need references that I can't access when initializing content.

	void loadTileSet();

	~content();
};