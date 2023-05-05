#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class EntityManager
{
public:
  EntityManager(EntityManager&) = delete;

  static EntityManager& Instance();

  const bool isEmpty(const std::string& type) const;

	const	std::vector<std::string>& types() const;
  const std::vector<Entity>& entitiesByType(const std::string& type) const;

	Entity addEntity(const std::string& type);

	void removeEntity(const std::string& type, Entity e);
  void update();

private:
	EntityManager();

	std::vector<std::string> m_types;

	std::map<std::string, std::vector<Entity>> m_entities;
	std::map<std::string, std::vector<Entity>> m_entitiesToAdd;
	std::map<std::string, std::vector<Entity>> m_entitiesToRemove;
};
