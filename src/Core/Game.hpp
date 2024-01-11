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

	void readIndex(const std::string& index);
  void start();

private:
  void readAssetIndex(const std::string& assetIndex);
  void readEntityIndex(const std::string& entityIndex);
  void readMapIndex(const std::string& mapIndex);

  std::vector<int> mapConfigs(const std::string& index);
};