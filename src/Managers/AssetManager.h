#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

class AssetManager
{
		// map with all our data classes, i.e. texture
		std::map<std::string, sf::Texture> m_assetMap;

		AssetManager();

	public:
    AssetManager(AssetManager&) = delete;

    static AssetManager& Instance();

		const sf::Texture& getAsset(const std::string name) const;

		void setAssets(std::map<std::string, std::string> assetMap);
};