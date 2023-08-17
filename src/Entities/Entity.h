#pragma once

#include "../MemoryPools/EntityComponentsMemoryPool.h"

#include <cstddef>

class Entity
{
public:
  Entity();
  Entity(const size_t id);

  const size_t id() const;

  bool operator == (const Entity& e) const;
  bool operator != (const Entity& e) const;

  template <typename T>
  T& getComponent()
  {
    return EntityComponentsMemoryPool::Instance().getComponent<T>(m_id);
  }

  template <typename T, typename... TArgs>
  void modifyComponent(TArgs&&... args)
  {
    auto& comp = EntityComponentsMemoryPool::Instance().getComponent<T>(m_id);
		comp = T(std::forward<TArgs>(args)...);
  }

private:
  size_t m_id = 0;
};
