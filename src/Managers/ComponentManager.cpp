#include "ComponentManager.h"

ComponentManager& ComponentManager::Instance()
{
  static ComponentManager INSTANCE;
  return INSTANCE;
}

const bool ComponentManager::isEmpty(const std::string& type) const
{
	return m_entities.at(type).empty();
}

const	std::vector<std::string>& ComponentManager::types() const
{
	return m_types;
}


const Entity& ComponentManager::player()
{
	return m_entities.at("Player").at(0);
}


const std::vector<Entity>& ComponentManager::entitiesByType(const std::string& type) const
{
	return m_entities.at(type);
}


Entity ComponentManager::addEntity(const std::string& type)
{
	Entity e(ComponentMemoryPool::Instance().activateEntity());
	m_entitiesToAdd[type].push_back(e);

	return e;
}


void ComponentManager::registerType(const std::string& type)
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

	if(!exists)
	{
		m_types.push_back(type);
		m_entities[type] = std::vector<Entity>();
	}
}

void ComponentManager::removeEntity(const std::string& type, Entity e)
{
	m_entitiesToRemove[type].push_back(e);
}


void ComponentManager::update()
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
ComponentManager::ComponentManager() { registerType("Player"); }