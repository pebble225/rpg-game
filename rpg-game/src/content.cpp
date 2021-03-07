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

//Takes a hex value in a string and writes it to x.
void writeHexValue(uint32_t& x, const std::string str)
{
	std::stringstream ss;

	ss << std::hex << str;

	ss >> x;//this overwrites the data correct?
}

content::content()
{
	
}

void content::init()
{
	loadTileSet();
}

void content::loadTileSet()
{
	//stop at every ';' and split by commas.

	//hopefully there isn't any deprecation issues with istream. Just learned about it...

	std::ifstream imgData("");

	while (!imgData.eof())
	{
		//read each character until it hits a ';'
		//store characters as it goes
	}
}

content::~content()
{
	
}
