#pragma once

#include <cstdint>

//maybe put the macros somewhere else eventually

#define TILEID_NULL 0x0000

//elevation

#define TILEID_GRASS_0 0x0001
#define TILEID_BEACH_SAND 0x0002
#define TILEID_SHALLOW_WATER 0x0003
#define TILEID_DEEP_WATER 0x0004
#define TILEID_MOUNTAIN_STONE 0x0005

class Tile
{
private:
	uint16_t id;
};