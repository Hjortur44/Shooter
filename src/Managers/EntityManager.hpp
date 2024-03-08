#pragma once

#include "../Entities/Entity.hpp"
#include "../MemoryPool/MemoryPool.hpp"

#include <vector>

class EntityManager
{
public:
  EntityManager(EntityManager&) = delete;

  static EntityManager& Instance();

	Entity addEntity();

	void removeEntity(const Entity entity);
  void update();

private:
	EntityManager();

	std::vector<Entity> m_entities;
	std::vector<Entity> m_entitiesToAdd;
	std::vector<Entity> m_entitiesToRemove;
};
