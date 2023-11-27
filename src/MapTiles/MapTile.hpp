#pragma once

#include <string>

class MapTile
{
public:
  MapTile(const std::string id);

  const std::string& id() const;

private:
  std::string m_id = "";
};
