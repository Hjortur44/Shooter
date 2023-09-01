#include "main.h"

int main(int argc, char* argv[])
{
  Game game;
  game.readEntityIndex("../configs/Entities/index.txt");
  game.readAssetIndex("../assets/index.txt");
  game.readMapIndex("../maps/index.txt");
  game.start();

	return 0;
}