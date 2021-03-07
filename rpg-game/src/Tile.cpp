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
	
}

Tile::~Tile()
{
	
}