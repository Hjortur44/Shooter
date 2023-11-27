#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <string>

class AssetManager
{
public:
  AssetManager(AssetManager&) = delete;

  static AssetManager& Instance();

  const sf::Texture getAsset(const std::string name);

  void setAssets(std::map<std::string, std::string> assetMap);

private:
  AssetManager();

  std::map<std::string, std::string> m_assetMap;
};
