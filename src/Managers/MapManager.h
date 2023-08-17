#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class MapManager
{
public:
  MapManager(MapManager&) = delete;

  static MapManager& Instance();

	const	std::map<std::string, std::vector<Vec2>>& mapTexturesAndLocations(const int number) const;

	void analizeMapConfigs(const std::map<int, std::string> map);

private:
  MapManager();

	std::map<int, std::map<std::string, std::vector<Vec2>>> m_map;
};
