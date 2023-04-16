#pragma once

#include "../Components/Components.h"

#include <string>
#include <tuple>
#include <vector>
#include <iostream>

typedef std::tuple<
    std::vector<CTransform>,
    std::vector<CLifespan>,
    std::vector<CCollision>,
    std::vector<CShape>,
    std::vector<CBoundingBox>
    > ComponentVectors;

class ComponentMemoryPool
{
  ComponentMemoryPool();

  ComponentVectors m_compVecs;

  const size_t MAX_CAPACITY = 3;

  std::vector<bool> m_actives;

public:
  ComponentMemoryPool(ComponentMemoryPool&) = delete;

  static ComponentMemoryPool& Instance();

  const std::vector<bool> getActives() const;

  const bool isActive(const size_t id) const;

  const size_t getMaxCapacity() const;
  const size_t addEntity();

  void removeEntity(const size_t id);

  template <typename T>
  std::vector<T>& getComponentVector()
  {
    return std::get<std::vector<T>>(m_compVecs);
  }

  template <typename T>
  T& getComponent(const size_t id)
  {
    return std::get<std::vector<T>>(m_compVecs).at(id);
  }

  template <typename T, typename... TArgs>
  void modifyComponent(const size_t id, TArgs&&... args)
  {
    getComponent<T>(id) = T(std::forward<TArgs>(args)...);
  }
};
