#include "AssetManager.h"

AssetManager& AssetManager::Instance()
{
  static AssetManager INSTANCE;
  return INSTANCE;
}


const sf::Texture AssetManager::getAsset(const std::string name)
{
	std::string path = m_assetMap.at(name);

	sf::Texture texture;
	texture.loadFromFile(path);

  return texture;
}


void AssetManager::setAssets(std::map<std::string, std::string> assetMap)
{
	m_assetMap = assetMap;
}


// private
AssetManager::AssetManager() {}
