#pragma once

#include "../Components/Components.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<
    std::vector<CBoundingBox>,
    std::vector<CCollision>,
    std::vector<CLifespan>,
    std::vector<CShape>,
    std::vector<CTransform>
    > ComponentVectors;

class ComponentMemoryPool
{
public:
  ComponentMemoryPool(ComponentMemoryPool&) = delete;

  static ComponentMemoryPool& Instance();

  const int addEntity();

  const std::vector<bool> getActives() const;

  const bool isActive(const int id) const;

  const int getMaxCapacity() const;

  void removeEntity(const int id);

  template <typename T>
  std::vector<T>& getComponentVector()
  {
    return std::get<std::vector<T>>(m_compVecs);
  }

  template <typename T>
  T& getComponent(const int id)
  {
    return std::get<std::vector<T>>(m_compVecs).at(id);
  }

  template <typename T, typename... TArgs>
  void modifyComponent(const int id, TArgs&&... args)
  {
    getComponent<T>(id) = T(std::forward<TArgs>(args)...);
  }

private:
  ComponentMemoryPool();

  ComponentVectors m_compVecs;

  const int MAX_CAPACITY = 3;

  std::vector<bool> m_actives;
};
