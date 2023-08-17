#pragma once

#include "../Entities/Entity.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/EntityComponentsMemoryPool.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class EntityComponentsManager
{
public:
  EntityComponentsManager(EntityComponentsManager&) = delete;

  static EntityComponentsManager& Instance();

	const	std::vector<std::string>& types() const;

  const std::vector<Entity>& entitiesByType(const std::string& type) const;

	Entity addEntity(const std::string& type);

	void registerType(const std::string& type);
	void removeEntity(const std::string& type, Entity e);
  void update();

private:
	EntityComponentsManager();

	const bool hasType(const std::string& type) const;

	std::vector<std::string> m_types;

	std::map<std::string, std::vector<Entity>> m_entities;
	std::map<std::string, std::vector<Entity>> m_entitiesToAdd;
	std::map<std::string, std::vector<Entity>> m_entitiesToRemove;
};
