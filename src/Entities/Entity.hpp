#pragma once

#include "../Managers/EntityManager.hpp"
#include "../MemoryPool/MemoryPool.hpp"

#include <iostream>

class Entity
{
public:
	template <typename T>
  T& getComponent()
  {
    return MemoryPool::Instance().getComponent<T>(m_id);
  }

	friend class EntityManager;

private:
  Entity(const size_t id);

  size_t m_id = 0;
};
