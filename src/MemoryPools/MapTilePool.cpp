#include "MapTilePool.hpp"

MapTilePool& MapTilePool::Instance()
{
  static MapTilePool INSTANCE(300);
  return INSTANCE;
}

// private
MapTilePool::MapTilePool(const size_t poolSize)
{
  auto& sp = getComponentType<CSprite>();

  for(size_t i = 0; i < poolSize; i++)
    sp.push_back(CSprite());
}