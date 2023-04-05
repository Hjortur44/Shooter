#include "AssetManager.h"

AssetManager& AssetManager::Instance()
{
  static AssetManager INSTANCE;
  return INSTANCE;
}

const std::map<std::string, std::string>& AssetManager::getAssets() const
{
	return m_assetMap;
}


void AssetManager::setAssets(std::map<std::string, std::string> assetMap)
{
	m_assetMap = assetMap;
}


// private
AssetManager::AssetManager() {}