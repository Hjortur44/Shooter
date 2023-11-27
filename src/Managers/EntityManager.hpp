#pragma once

#include "../Entities/Entity.hpp"
#include "../Math/Vec2.hpp"
#include "../MemoryPools/EntityPool.hpp"

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

  const std::vector<Entity>& allEntities() const;

	Entity addEntity();

	void purgeDeadEntities();
  void update();

  template <typename T>
  T& getComponentForEntity(const Entity& entity)
  {
    return EntityPool::Instance().getComponentForEntity<T>(entity.id());
  }

  template <typename T>
  std::vector<T>& getComponentType()
  {
    return EntityPool::Instance().getComponentType<T>();
  }

  template <typename T, typename... TArgs>
  void modifyComponent(const Entity& entity, TArgs&&... args)
  {
    auto& comp = EntityPool::Instance().getComponentForEntity<T>(entity.id());
		comp = T(std::forward<TArgs>(args)...);
  }

private:
	EntityManager();

	std::vector<Entity> m_entities;
	std::vector<Entity> m_entitiesToAdd;
	std::vector<Entity> m_entitiesToRemove;
};
