#include "AssetManager.hpp"

AssetManager& AssetManager::Instance()
{
  static AssetManager INSTANCE;
  return INSTANCE;
}


const sf::Texture& AssetManager::textures(const std::string& name) const
{
	return m_textures.at(name);
}


void AssetManager::update(const std::vector<std::string>& textureNames, const std::vector<std::string>& assets)
{
	for(size_t i = 0; i < textureNames.size(); i++)
	{
		sf::Texture t;
		t.loadFromFile(assets.at(i));
		m_textures[textureNames.at(i)] = t;
	}
}


// private
AssetManager::AssetManager() {}