#include "EntityManager.hpp"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


const std::vector<Entity>& EntityManager::entities() const
{
	return m_entities;
}

Entity EntityManager::addEntity()
{
	Entity e(MemoryPool::Instance().activateEntity());
	m_entitiesToAdd.push_back(e);

	return e;
}


void EntityManager::removeEntity(const Entity& entity)
{
	m_entitiesToRemove.push_back(entity);
}


void EntityManager::update()
{
	for(Entity e: m_entitiesToRemove)
	{
    std::erase_if(m_entities, [e](const Entity& entity)
    {
     	return e.m_id == entity.m_id;
    });
	}

	for(Entity e: m_entitiesToAdd)
	{
		m_entities.push_back(e);
	}

	m_entitiesToAdd.clear();
	m_entitiesToRemove.clear();
}


// private
EntityManager::EntityManager() {}