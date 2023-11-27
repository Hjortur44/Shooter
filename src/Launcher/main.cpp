#include "main.hpp"

int main(int argc, char* argv[])
{
	std::string domain = "/home/hjortur/Documents/Gits/Shooter";

  Game game;
  game.readEntityIndex(domain + "/configs/Entities/index.txt");
  game.readAssetIndex(domain + "/assets/index.txt");
  game.readMapIndex(domain + "/maps/index.json");
  game.start();

	return 0;
}