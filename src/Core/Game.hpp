#pragma once

#include "GameEngine.hpp"
#include "../Managers/AssetManager.hpp"
#include "../Managers/MapManager.hpp"
#include "../Logger/Profiler.hpp"
#include "../../nlohmann/json.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using Json = nlohmann::json;

class Game
{
public:
  Game();
  ~Game();

	void fileRead(const std::string& file);
  void start();

private:
	std::vector<std::string> files(const std::string& path, const Json& data);
};