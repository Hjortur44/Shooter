#include "main.h"

int main(int argc, char* argv[])
{
  Game game;
  game.readEntityConfigs("/home/hjortur/Documents/Gits/Shooter/configs/Entities/index.txt");
  game.readAssetTextures("/home/hjortur/Documents/Gits/Shooter/assets/index.txt");
  game.start();
}
