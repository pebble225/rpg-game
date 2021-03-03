#include <iostream>
#include <fstream>

std::ofstream file;
const std::string resDir = "../rpg-game/res/";

void addTile(const std::string tileID, const std::string imageURL)
{
	file << tileID << "," << imageURL << ";";
}

//the directory this is accessed from is rpg-game/rpg-game

int main()
{
	file = std::ofstream("../rpg-game/res/imgData");

	addTile("sampleTile", "./res/img/sample");

	file.close();
}