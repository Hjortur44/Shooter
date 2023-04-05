#include "main.h"

#include <iostream>

int main(int argc, char* argv[])
{
	std::string topURL = "/home/hjortur/Desktop/sfml/Game";
  Game game;
	game.readEntityConfigs(topURL + "/configs/Entities/index.txt");
	game.readAssetTextures(topURL + "/assets/index.txt");
	game.start();
}