#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "GameConstants.h"

#include <cstdint>

#include <iostream>
#include <string>

//maybe put the tile_id namespace somewhere else eventually

typedef uint16_t tileID;

namespace tile_ids
{
	//null tile

	constexpr tileID null = 0x0000;

	//elevation terrain tiles

	constexpr tileID grass = 0x0001;
	constexpr tileID beachSand = 0x0002;
	constexpr tileID shallowWater = 0x0003;
	constexpr tileID deepWater = 0x0004;
	constexpr tileID mountainStone = 0x0005;

	constexpr tileID sampleTile = 0xF001;
};

class Tile
{
private:
	tileID id;
	std::string src;

	SDL_Texture* buffer;

public:
	Tile();
	Tile(tileID id, std::string src);

	tileID getID();
	void setID(tileID id);

	void loadImage(SDL_Renderer* g);

	void drawTile(SDL_Renderer* g, int x, int y);

	~Tile();
};