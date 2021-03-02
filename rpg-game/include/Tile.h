#pragma once

#include <SDL.h>

#include <cstdint>

//maybe put the tile_id namespace somewhere else eventually

typedef uint16_t tileID;

namespace tile_ids//should contents of namespace go in header?
{
	//null tile

	constexpr tileID null = 0x0000;

	//elevation terrain tiles

	constexpr tileID grass = 0x0001;
	constexpr tileID beachSand = 0x0002;
	constexpr tileID shallowWater = 0x0003;
	constexpr tileID deepWater = 0x0004;
	constexpr tileID mountainStone = 0x0005;
};

class Tile
{
private:
	tileID id;
public:
	Tile(tileID id);

	tileID getID();
	void setID(tileID id);

	void drawTile(const SDL_Renderer* g);
};