#pragma once

#include "../EntityComponents/Components.h"

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<
    std::vector<CBoundingBox>,
    std::vector<CCollision>,
    std::vector<CController>,
    std::vector<CLifespan>,
    std::vector<CMovement>,
    std::vector<CTexture>,
    std::vector<CTransform>
    > ComponentVectors;

class EntityComponentsMemoryPool
{
public:
  EntityComponentsMemoryPool(EntityComponentsMemoryPool&) = delete;

  static EntityComponentsMemoryPool& Instance();

  const std::vector<bool>& actives() const;

	const size_t activateEntity();
  const size_t poolSize() const;

	void deactivateEntity(const size_t id);

  template <typename T>
  T& getComponent(const size_t id)
  {
    return std::get<std::vector<T>>(m_compVecs).at(id);
  }

private:
  EntityComponentsMemoryPool(const size_t poolSize);

  ComponentVectors m_compVecs;

  std::vector<bool> m_actives;

  size_t m_poolSize = 0;
};
