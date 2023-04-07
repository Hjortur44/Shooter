#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Managers/EntityManager.h"

#include <vector>
#include <iostream>

class Spawner
{
 		ComponentMemoryPool&  m_compPool      = ComponentMemoryPool::Instance();
		AssetManager&         m_assetManager  = AssetManager::Instance();
		ConfigurationManager& m_configManager = ConfigurationManager::Instance();
		EntityManager&        m_entityManager = EntityManager::Instance();

		sf::Texture m_texture;

		std::map<std::string, int> m_configMap;

		size_t m_counter = 0;

		void init();

	public:
		Spawner();
		~Spawner();

		void spawnEntity();
};