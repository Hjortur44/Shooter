#include "main.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
/*
	for(int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
*/

	std::string mainFolder = "/home/hjortur/Documents/Gits/Shooter";

  Game game;
 	game.fileRead(mainFolder + "/assets/index.json");

//  game.fileRead(mainFolder + "/entities/index.json");
  game.fileRead(mainFolder + "/configurations/maps/index.json");
  game.start();

	return 0;
}