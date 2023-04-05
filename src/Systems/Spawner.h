#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "../Managers/ConfigurationManager.h"
#include "../Managers/AssetManager.h"

class Spawner
{
 		ComponentMemoryPool& m_compPool       = ComponentMemoryPool::Instance();
		ConfigurationManager& m_configManager = ConfigurationManager::Instance();
		AssetManager& m_assetManager          = AssetManager::Instance();

		sf::Texture m_texture;

		std::map<std::string, int> m_configMap;

		void init(const std::string& name);

	public:
		Spawner();
		~Spawner();

		void spawnEntity(const std::string& name);
};