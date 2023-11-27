#pragma once

#include "../MemoryPools/MapTilePool.hpp"

#include <map>
#include <vector>

typedef std::map<int, std::map<std::string, std::vector<int>>> ConfigMap;

class MapTileManager
{
public:
  MapTileManager(MapTileManager&) = delete;

  static MapTileManager& Instance();

	void setMapTileConfigs(ConfigMap configs);

  template <typename T>
  std::vector<T>& getComponentType()
  {
    return MapTilePool::Instance().getComponentType<T>();
  }

private:
  MapTileManager();

	ConfigMap m_configs;
};
