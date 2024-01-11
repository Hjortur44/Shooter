#include "main.hpp"

int main(int argc, char* argv[])
{
	std::string domain = "/home/hjortur/Documents/Gits/Shooter";

  Game game;
  game.readIndex(domain + "/entities/index.json");
  game.readIndex(domain + "/assets/index.json");
  game.readIndex(domain + "/maps/index.json");
  game.start();

	return 0;
}