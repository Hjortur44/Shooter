#pragma once

#include "Components.h"

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
    const size_t             MAX_CAPACITY = 1000;

    std::vector<bool>        m_actives    = {false};
    ComponentVectors         m_compVecs;

    ComponentMemoryPool();

  public:
    ComponentMemoryPool(ComponentMemoryPool&) = delete;

    static ComponentMemoryPool& Instance();

		const size_t getMaxCapacity();
		const size_t getFreeId();

		void freeUpId(const size_t id);

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
    void addComponent(const size_t id, TArgs&&... args)
    {
	    auto& comp = getComponent<T>(id);
	    comp = T(std::forward<TArgs>(args)...);
	    comp.active = true;
    }

    template <typename T>
    void removeComponent(const size_t id)
    {
      auto& comp = getComponent<T>(id);
			comp = T();
    }
};