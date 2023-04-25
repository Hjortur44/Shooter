#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class EntityManager
{
public:
  EntityManager(EntityManager&) = delete;

  static EntityManager& Instance();

	const Entity entity(const size_t id) const;
	const std::vector<Entity> entities() const;

	Entity addEntity();
	Entity addPlayer();

	void removeEntity(Entity e);
  void update();

private:
	EntityManager();

	std::vector<Entity> m_entities;
	std::vector<Entity> m_entitiesToAdd;
	std::vector<Entity> m_entitiesToRemove;
};
