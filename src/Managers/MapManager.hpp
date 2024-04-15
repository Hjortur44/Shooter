#pragma once

#include <map>
#include <vector>

class MapManager
{
public:
  MapManager(MapManager&) = delete;

  static MapManager& Instance();

 	const std::map<std::string, std::vector<int>>& textures(const int mapNumber) const;

  void update(const int mapNumber, const std::map<std::string, std::vector<int>> textureMap);

private:
	MapManager();

	std::map<int, std::map<std::string, std::vector<int>>> m_textures;
};
