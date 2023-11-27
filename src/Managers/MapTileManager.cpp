#include "MapTileManager.hpp"

MapTileManager& MapTileManager::Instance()
{
  static MapTileManager INSTANCE;
  return INSTANCE;
}


void MapTileManager::setMapTileConfigs(ConfigMap configs)
{
	m_configs = configs;
}


// private
MapTileManager::MapTileManager() {}