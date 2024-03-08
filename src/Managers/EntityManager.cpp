#include "EntityManager.hpp"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


Entity EntityManager::addEntity()
{
	size_t id = MemoryPool::Instance().activateEntity();
	Entity e(id);

	if(id > 0)
		m_entitiesToAdd.push_back(e);

	return e;
}

void EntityManager::removeEntity(const Entity entity)
{
	m_entitiesToRemove.push_back(entity);
}


void EntityManager::update()
{
	for(Entity e: m_entitiesToRemove)
	{
    std::erase_if(m_entities, [e](const Entity entity)
    {
     	return e.id() == entity.id();
    });
	}

	for(Entity e: m_entitiesToAdd)
	{
		m_entities.push_back(e);
	}

	m_entitiesToAdd.clear();
}


// private
EntityManager::EntityManager() {}