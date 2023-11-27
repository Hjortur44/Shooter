#pragma once

#include "../Components/CSprite.hpp"

#include <tuple>
#include <vector>

typedef std::tuple<
    std::vector<CSprite>
    > MapComponentVectors;

class MapTilePool
{
public:
  MapTilePool(MapTilePool&) = delete;

  static MapTilePool& Instance();

  template <typename T>
  std::vector<T>& getComponentType()
  {
    return std::get<std::vector<T>>(m_compVecs);
  }

private:
  MapTilePool(const size_t poolSize);

  MapComponentVectors m_compVecs;
};