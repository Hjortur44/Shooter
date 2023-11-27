#pragma once

#include "GameEngine.hpp"

#include "../Managers/AssetManager.hpp"
#include "../Managers/ConfigurationManager.hpp"
#include "../Managers/MapTileManager.hpp"

#include "../../nlohmann/json.hpp"

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
  std::vector<int> mapConfigs(const std::string& index);
};