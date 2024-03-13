#pragma once

#include "../Components/CBoundingBox.hpp"
#include "../Components/CLifespan.hpp"
#include "../Components/CSprite.hpp"
#include "../Components/CTransform.hpp"

#include <tuple>
#include <vector>

typedef std::tuple<
    std::vector<CBoundingBox>,
    std::vector<CLifespan>,
    std::vector<CSprite>,
    std::vector<CTransform>
    > ComponentVectors;

class MemoryPool
{
public:
  MemoryPool(MemoryPool&) = delete;

  static MemoryPool& Instance();

	const size_t activateEntity();

	void deactivateEntity(const size_t id);

  template <typename T>
  T& getComponent(const size_t id)
  {
    return std::get<std::vector<T>>(m_compVecs).at(id);
  }

private:
  MemoryPool(const size_t poolSize);

  ComponentVectors m_compVecs;

  std::vector<bool> m_actives;
};
