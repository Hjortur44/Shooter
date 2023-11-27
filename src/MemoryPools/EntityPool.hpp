#pragma once

#include "../Components/CBoundingBox.hpp"
#include "../Components/CLifespan.hpp"
#include "../Components/CSprite.hpp"
#include "../Components/CTransform.hpp"

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<
    std::vector<CBoundingBox>,
    std::vector<CLifespan>,
    std::vector<CSprite>,
    std::vector<CTransform>
    > ComponentVectors;

class EntityPool
{
public:
  EntityPool(EntityPool&) = delete;

  static EntityPool& Instance();

	const size_t activateEntity();

	void deactivateEntity(const size_t id);

  template <typename T>
  T& getComponentForEntity(const size_t id)
  {
    return std::get<std::vector<T>>(m_compVecs).at(id);
  }

  template <typename T>
  std::vector<T>& getComponentType()
  {
    return std::get<std::vector<T>>(m_compVecs);
  }

private:
  EntityPool(const size_t poolSize);

  ComponentVectors m_compVecs;

  std::vector<bool> m_actives;
};
