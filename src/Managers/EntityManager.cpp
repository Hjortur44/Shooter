#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


const Entity EntityManager::entity(const size_t id) const
{
	return m_entities.at(id);
}


const std::vector<Entity> EntityManager::entities() const
{
	return m_entities;
}


Entity EntityManager::addEntity()
{
	Entity e(ComponentMemoryPool::Instance().activateEntity());
	m_entitiesToAdd.push_back(e);
	return e;
}


Entity EntityManager::addPlayer()
{
	Entity e(ComponentMemoryPool::Instance().activatePlayer());
	m_entitiesToAdd.push_back(e);
	return e;
}


void EntityManager::removeEntity(Entity e)
{
	m_entitiesToRemove.push_back(e);
}


void EntityManager::update()
{
	for(Entity e : m_entitiesToRemove)
	{
		ComponentMemoryPool::Instance().deactivateEntity(e.id());
		m_entities.erase(std::remove_if(m_entities.begin(),
																	  m_entities.end(),
																	  [e](const Entity x)
																		 { return x.id() == e.id(); }));
	}

	for(Entity e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
	}

	m_entitiesToRemove.clear();
	m_entitiesToAdd.clear();
}

// private
EntityManager::EntityManager(){}