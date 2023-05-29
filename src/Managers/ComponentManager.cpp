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
ComponentManager::ComponentManager()
{
	m_types.push_back("Bullet");
	m_types.push_back("Enemy");
	m_types.push_back("Player");

	m_types.push_back("Wall");

	for(std::string& t : m_types)
		m_entities[t] = std::vector<Entity>();
}