#pragma once

#include "GameEngine.hpp"
#include "../Managers/EntityManager.hpp"
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

	void fileRead(const std::string& type, const std::string& file);
  void start();

private:
	std::map<std::string, std::vector<std::string>> m_list;
};