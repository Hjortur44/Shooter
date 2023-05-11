#include "main.h"

int main(int argc, char* argv[])
{
  Game game;
	game.readAssetConfigs("/home/hjortur/Documents/Gits/Shooter/configs/Assets/index.txt");
  game.readEntityConfigs("/home/hjortur/Documents/Gits/Shooter/configs/Entities/index.txt");
  game.readAssetTextures("/home/hjortur/Documents/Gits/Shooter/assets/index.txt");
  game.start();
}
