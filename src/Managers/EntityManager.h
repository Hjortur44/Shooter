#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <iostream>

class EntityManager
{
		EntityManager();

		void createEntity();

	public:
    EntityManager(EntityManager&) = delete;

    static EntityManager& Instance();
};