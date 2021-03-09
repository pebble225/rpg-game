#include "../include/content.h"

/*

A bit of rethinking about how the world is going to generate.

I want to limit the map size and motivate the player to explore vastly
far areas of the map.

Having special biomes that spawn far away from spawn and making
traveling more feesible can make a randomly generated rpg sandbox
have more drive than just grinding levels and buying gear.

The world dimensions are changing to 16384x8192.
The map will wrap around on the x axis while the y axis will remain restrained

The new idea is to make a convincing world map using two or more layers
of perlin noise maps.

So for example, the first iteration will generate the main continents.
The land-sea ratio should be about 3:2 in favor of land. The following
iterations will read whether the region is land or sea and generate the
more fine details of the terrain

The 65536x65536 dimension isn't gonna work lol. The tiles are still going to be
saved to file only if the player is present to generate them.

Storing NPCs is going to be weird. Either they're stored entity by entity or
they have to be "migrated" to different chunks as they move around.
It's totally doable though.

I am thinking of adding other "realms" the player can go to, but that will
be much much later in development.

This is all of the detail that's important for now. After I get the tiles working, I'm gonna
focus on the map view FIRST and then start worrying about sprites for the standard view.
Crusty dev sprites inbound.

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
		std::getline(dataStream, tileSrc_s, ',');

		//Step 2: Create Tile object and load image

		uint32_t tileID_t = 0x0;

		writeHexValue(tileID_t, tileID_s);

		tileID_t &= 0x0000FFFF;//mask to 16 bit tile value just to be safe

		TileSet[tileID_t] = new Tile(tileID_t, tileSrc_s);

		TileSet[tileID_t]->loadImage(g);
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

	TileSet[tile_ids::sampleTile]->drawTile(g, x, (int)(sin((double)x / 10.0)*50.0 + 400.0));
	
	SDL_RenderPresent(g);
}

content::~content()
{
	
}
