#include "EntityManager.hpp"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


const std::vector<Entity>& EntityManager::allEntities() const
{
	return m_entities;
}


Entity EntityManager::addEntity()
{
	Entity e(EntityPool::Instance().activateEntity());
	m_entitiesToAdd.push_back(e);

	return e;
}


void EntityManager::update()
{
	purgeDeadEntities();

	for(Entity e: m_entitiesToAdd)
	{
		m_entities.push_back(e);
	}

	m_entitiesToAdd.clear();
}


// private
EntityManager::EntityManager() {}

void EntityManager::purgeDeadEntities()
{
	//Entity e = m_entities.at(1);
//	m_entities.erase(m_entities.begin() + e.id());
}