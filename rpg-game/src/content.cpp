#include "../include/content.h"

/*

A bit of rethinking about how the world is going to generate.

I want to limit the map size and motivate the player to explore vastly
far areas of the map.

Having special biomes that spawn far away from spawn and making
traveling more feesible can make a randomly generated rpg sandbox
have more drive than just grinding levels and buying gear.

The world dimensions are changing to 16384x8192.

*/

//yes this is going to be moved later
void writeHexValue(uint32_t& x, const std::string str)
{
	std::stringstream ss;

	ss << std::hex << str;

	ss >> x;
}

content::content()
{
	
}

void content::init(SDL_Renderer* g)
{
	loadTileSet(g);
}

void content::loadTileSet(SDL_Renderer* g)
{
	//stop at every ';' and split by ','.

	std::ifstream imgData("./res/imgData");//this url might change with cmake integration
	
	if (!imgData.good())
	{
		std::cout << "Unable to locate imgData resource!" << std::endl;
	}

	while (!imgData.eof())
	{
		//Step 1: Read data from single Tile section

		std::string data;

		std::getline(imgData, data, ';');

		if (data == "#")
			break;

		std::stringstream dataStream(data);
		
		std::string tileID_s, tileSrc_s;

		std::getline(dataStream, tileID_s, ',');
		std::getline(dataStream, tileSrc_s, ',');//there is only one comma. How does this run?

		//Step 2: Create Tile object and load image

		uint32_t tileID_t = 0x0;

		writeHexValue(tileID_t, tileID_s);
		
		tileID_t &= 0x0000FFFF;//mask to 16 bit tile value just to be safe

		TileSet[tileID_t] = Tile(tileID_t);
		TileSet[tileID_t].loadImage(g, tileSrc_s);

		//TileSet[tileID_t] = new Tile(tileID_t);

		//TileSet[tileID_t]->loadImage(g, tileSrc_s);
	}
}

int x = 0;

void content::Update()
{
	x++;
}

void content::Render(SDL_Renderer* g, SDL_Surface* buffer)
{
	SDL_SetRenderDrawColor(g, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(g);
	
	SDL_RenderPresent(g);
}

content::~content()
{
	
}
