#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}

const bool EntityManager::isEmpty(const std::string& type) const
{
	return m_entities.at(type).empty();
}

const	std::vector<std::string>& EntityManager::types() const
{
	return m_types;
}


const Entity& EntityManager::player()
{
	return m_entities.at("Player").at(0);
}


const std::vector<Entity>& EntityManager::entitiesByType(const std::string& type) const
{
	return m_entities.at(type);
}


Entity EntityManager::addEntity(const std::string& type)
{
	Entity e(ComponentMemoryPool::Instance().activateEntity());
	m_entitiesToAdd[type].push_back(e);

	return e;
}


void EntityManager::removeEntity(const std::string& type, Entity e)
{
	m_entitiesToRemove[type].push_back(e);
}


void EntityManager::update()
{
	for(const auto& [key, value] : m_entitiesToRemove)
	{
		m_entities[key].erase(std::remove_if(m_entities[key].begin(), m_entities[key].end(),
			[value](const Entity& e) {
				if(std::find(value.begin(), value.end(), e) != value.end())
				{
					ComponentMemoryPool::Instance().deactivateEntity(e.id());
					return true;
				}
				else
					{ return false; }}));
	}

	for(const auto& [key, value] : m_entitiesToAdd)
	{
		for(const Entity& v : value)
		{
			m_entities[key].push_back(v);
		}
	}

	m_entitiesToRemove.clear();
	m_entitiesToAdd.clear();
}

// private
EntityManager::EntityManager()
{
	m_types.push_back("Bullet");
	m_types.push_back("Enemy");
	m_types.push_back("Player");
	m_types.push_back("Outer_wall");

	for(std::string& t : m_types)
		m_entities[t] = std::vector<Entity>();
}