#include "EntityComponentsManager.h"

EntityComponentsManager& EntityComponentsManager::Instance()
{
  static EntityComponentsManager INSTANCE;
  return INSTANCE;
}


const	std::vector<std::string>& EntityComponentsManager::types() const
{
	return m_types;
}


const std::map<std::string, std::vector<Entity>>& EntityComponentsManager::allEntities() const
{
	return m_entities;
}


const std::vector<Entity>& EntityComponentsManager::entitiesByType(const std::string& type) const
{
	if(!hasType(type))
		return m_entities.at("Empty");

	return m_entities.at(type);
}


Entity EntityComponentsManager::addEntity(const std::string& type)
{
	Entity e(EntityComponentsMemoryPool::Instance().activateEntity());
	m_entitiesToAdd[type].push_back(e);

	return e;
}


void EntityComponentsManager::registerType(const std::string& type)
{
	if(!hasType(type))
	{
		m_types.push_back(type);
		m_entities[type] = std::vector<Entity>();
	}
}


void EntityComponentsManager::removeEntity(const std::string& type, Entity e)
{
	m_entitiesToRemove[type].push_back(e);
}


void EntityComponentsManager::update()
{
	for(const auto& [key, value] : m_entitiesToRemove)
	{
		m_entities[key].erase(std::remove_if(m_entities[key].begin(), m_entities[key].end(),
			[value](const Entity& e) {
				if(std::find(value.begin(), value.end(), e) != value.end())
				{
					EntityComponentsMemoryPool::Instance().deactivateEntity(e.id());
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
EntityComponentsManager::EntityComponentsManager()
{
	registerType("Empty");
}


const bool EntityComponentsManager::hasType(const std::string& type) const
{
	bool exists = false;

	for(std::string s : m_types)
	{
		if(s == type)
		{
			exists = true;
			break;
		}
	}

	return exists;
}