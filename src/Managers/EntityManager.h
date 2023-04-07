#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"

#include <map>
#include <vector>
#include <iostream>

class EntityManager
{
		EntityManager();

		void createEntity();

		AssetManager&         m_assetManager  = AssetManager::Instance();
		ConfigurationManager& m_configManager = ConfigurationManager::Instance();

		std::map<size_t, std::vector<size_t>> m_entities;
		std::map<std::string, int> m_configMap;

		sf::Texture m_texture;

	public:
    EntityManager(EntityManager&) = delete;

    static EntityManager& Instance();

  	const std::map<size_t, std::vector<size_t>>& getEntities() const;
};