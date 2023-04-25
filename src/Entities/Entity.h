#pragma once

#include "../MemoryPools/ComponentMemoryPool.h"

#include <cstddef>

class Entity
{
public:
  Entity();
  Entity(const size_t id);

  const size_t id() const;

  template <typename T>
  T& getComponent()
  {
    return ComponentMemoryPool::Instance().getComponent<T>(m_id);
  }

  template <typename T, typename... TArgs>
  void modifyComponent(TArgs&&... args)
  {
    auto& comp = ComponentMemoryPool::Instance().getComponent<T>(m_id);
		comp = T(std::forward<TArgs>(args)...);
  }

private:
  size_t m_id = 0;
};
