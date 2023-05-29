#pragma once

#include "GameEngine.h"

#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Game
{
public:
  Game();

  void readAssetConfigs(const std::string& configIndex);
  void readAssetTextures(const std::string& textureIndex);
  void readEntityConfigs(const std::string& configIndex);

  void start();

private:
	std::vector<Vec2>   assetConfigs(const std::string& index);
  std::vector<int> entityConfigs(const std::string& index);
};
