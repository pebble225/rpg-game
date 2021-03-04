#include <iostream>
#include <fstream>

std::ofstream file;
const std::string resDir = "../rpg-game/res/";

void addTile(const std::string tileID, const std::string imageURL)
{
	file << tileID << "," << imageURL << ";";
}

//the directory this is accessed from is rpg-game/rpg-game

/*

Another problem down the road.

I am entering the Tile ids by the number so that
content::loadTileSet() can correspond the number with the tileID.

Copying the tileID namespace seems like a bad solution,
so for now I'm just going to enter the numbers.

*/

int main()
{
	file = std::ofstream("../rpg-game/res/imgData");

	addTile("F001", "./res/img/sample.png");

	file.close();
}