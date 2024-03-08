#include "main.hpp"

int main(int argc, char* argv[])
{
	std::string mainFolder = "/home/hjortur/Documents/Gits/Shooter";

  Game game;
  game.fileRead("assets", mainFolder + "/assets/images.json");
//  game.fileRead(mainFolder + "/entities/index.json");
//  game.fileRead("map#0", mainFolder + "/configurations/maps/map#0/textures.json");
  game.start();

	return 0;
}