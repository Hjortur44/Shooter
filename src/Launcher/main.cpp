#include "main.h"

int main(int argc, char* argv[])
{
  Game game;
  game.readEntityConfigs("/home/hjortur/codeblocks_workspace/Game/configs/Entities/index.txt");
  game.readAssetTextures("/home/hjortur/codeblocks_workspace/Game/assets/index.txt");
  game.start();
}
