#include "../include/Tile.h"

Tile::Tile(tileID id)
{
	this->id = id;
}

tileID Tile::getID()
{
	return id;
}

void Tile::setID(tileID id)
{
	this->id = id;
}

void Tile::drawTile(const SDL_Renderer* g)
{
	switch (id)
	{
	
		//need to do image handling before continuing

	case tile_ids::null:
	default:
		break;
	}
}