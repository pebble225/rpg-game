#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <cstdint>

//maybe put the tile_id namespace somewhere else eventually

typedef uint16_t tileID;

//namespace tile_ids//should contents of namespace go in header?
//{
//	//null tile
//
//	constexpr tileID null = 0x0000;
//
//	//elevation terrain tiles
//
//	constexpr tileID grass = 0x0001;
//	constexpr tileID beachSand = 0x0002;
//	constexpr tileID shallowWater = 0x0003;
//	constexpr tileID deepWater = 0x0004;
//	constexpr tileID mountainStone = 0x0005;
//};

class Tile
{
private:
	tileID id;
	SDL_Surface* buffer;

public:
	Tile(tileID id);

	tileID getID();
	void setID(tileID id);

	void drawTile(const SDL_Renderer* g);
};

/*

is tiles::initTiles a bad idea? Do I need to make an instance of the tiles namespace?
if two source files include this header, will one be initialized and the other not?

*/

namespace tiles
{
	Tile sampleTile;

	Tile grass;
	Tile beachSand;
	Tile shallowWater;
	Tile deepWater;
	Tile mountainStone;

	void initTiles();//This function will read the data from the imgData file and initialize the Tile objects
}