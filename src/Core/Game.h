#pragma once

#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "GameEngine.h"

#include <fstream>
#include <string>
#include <iostream>

class Game
{
  public:
    Game();

		void readEntityConfigs(const std::string& configIndex);
		void readAssetConfigs(const std::string& configIndex);
		void readAssetTextures(const std::string& textureIndex);

		void start();
};