#pragma once

#include "GameEngine.h"

#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Managers/MapManager.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Game
{
public:
  Game();
  ~Game();

  void readAssetIndex(const std::string& assetIndex);
  void readEntityIndex(const std::string& entityIndex);
  void readMapIndex(const std::string& mapIndex);

  void start();

private:
  std::vector<int> entityConfigs(const std::string& index);
};
