#include "../include/Tile.h"

Tile::Tile()
{
	id = NULL;
	src = "";
	buffer = NULL;
}

Tile::Tile(tileID id, std::string src)
{
	this->id = id;
	this->src = src;
}

tileID Tile::getID()
{
	return id;
}

void Tile::setID(tileID id)
{
	this->id = id;
}

void Tile::loadImage(SDL_Renderer* g)
{
	const char* src_cstr = src.c_str();

	SDL_Surface* temp = IMG_Load(src_cstr);

	if (temp == NULL)
	{
		std::cout << "Couldn't load image at \"" << src << "\"." << std::endl;
		return;
	}
	else
	{
		buffer = SDL_CreateTextureFromSurface(g, temp);
	}

	if (buffer == NULL)
	{
		std::cout << "An error occured when creating the Texture for image at \"" << src << "\"." << std::endl;
		return;
	}

	SDL_FreeSurface(temp);
}

void Tile::drawTile(SDL_Renderer* g, int x, int y)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = GameConstants::TileSize;
	r.h = GameConstants::TileSize;

	SDL_RenderCopy(g, buffer, NULL, &r);
}

Tile::~Tile()
{
	
}