#pragma once

#include <string>
#include <map>
#include <iostream>

class AssetManager
{
		// map with all our data classes, i.e. texture
		std::map<std::string, std::string> m_assetMap;

		AssetManager();

	public:
    AssetManager(AssetManager&) = delete;

    static AssetManager& Instance();

		const std::map<std::string, std::string>& getAssets() const;

		void setAssets(std::map<std::string, std::string> assetMap);
};