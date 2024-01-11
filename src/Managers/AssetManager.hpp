#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <string>
#include <vector>

class AssetManager
{
public:
  AssetManager(AssetManager&) = delete;

  static AssetManager& Instance();

  const sf::Texture& getAsset(const std::string name);

  void setAssets(std::map<std::string, std::string> assetMap);

private:
  AssetManager();

  bool contains(const std::string& name);

  std::map<std::string, std::string> m_assetMap;
  std::map<std::string, sf::Texture> m_textureMap;
};
