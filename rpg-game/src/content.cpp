#include "../include/content.h"

/*

Takes a hex value in a string and writes it to x.

*/

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

	std::ifstream imgData;

	imgData.open("../res/imgData");

	while (!imgData.eof())
	{
		//read each character until it hits a ';'
		//store characters as it goes
	}

	imgData.close();
}