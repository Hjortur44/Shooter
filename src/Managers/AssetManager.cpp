#include "AssetManager.hpp"

AssetManager& AssetManager::Instance()
{
  static AssetManager INSTANCE;
  return INSTANCE;
}


const sf::Texture& AssetManager::getAsset(const std::string name)
{
	if(!contains(name))
	{
		std::string path = m_assetMap.at(name);

		sf::Texture texture;
		texture.loadFromFile(path);

		m_textureMap[name] = texture;
	}

  return m_textureMap.at(name);
}


void AssetManager::setAssets(std::map<std::string, std::string> assetMap)
{
	m_assetMap = assetMap;
}


// private
AssetManager::AssetManager() {}

bool AssetManager::contains(const std::string& name)
{
	bool contains = false;

  if(auto search = m_textureMap.find(name); search != m_textureMap.end())
  	contains = true;

  return contains;
}
