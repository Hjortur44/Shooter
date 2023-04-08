#include "AssetManager.h"

AssetManager& AssetManager::Instance()
{
  static AssetManager INSTANCE;
  return INSTANCE;
}


const sf::Texture& AssetManager::getAsset(const std::string name) const
{
	return m_assetMap.at(name);
}


void AssetManager::setAssets(std::map<std::string, std::string> assetMap)
{
	sf::Texture t;

	for(const auto& [key, value] : assetMap)
	{
		t.loadFromFile(value);
		m_assetMap[key] = t;
	}
}


// private
AssetManager::AssetManager() {}