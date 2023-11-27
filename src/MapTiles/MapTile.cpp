#include "MapTile.hpp"

MapTile::MapTile(const std::string id) : m_id(id) {}

const std::string& MapTile::id() const
{
  return m_id;
}