#include "MapManager.hpp"

MapManager& MapManager::Instance()
{
  static MapManager INSTANCE;
  return INSTANCE;
}


const std::map<std::string, std::vector<int>>& MapManager::textures(const int mapNumber) const
{
	return m_textures.at(mapNumber);
}


void MapManager::update(const int mapNumber, const std::map<std::string, std::vector<int>> textureMap)
{
	m_textures[mapNumber] = textureMap;
}


// private
MapManager::MapManager() {}