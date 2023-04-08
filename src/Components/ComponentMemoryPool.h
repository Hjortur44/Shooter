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
    ComponentMemoryPool();

    const size_t             MAX_CAPACITY = 1000;

    ComponentVectors         m_compVecs;

		size_t m_counter = 0;

  public:
    ComponentMemoryPool(ComponentMemoryPool&) = delete;

    static ComponentMemoryPool& Instance();

		const size_t getMaxCapacity();

		void activateNext();
		void freeUpId();

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
    }

    template <typename T>
    void removeComponent(const size_t id)
    {
      auto& comp = getComponent<T>(id);
			comp = T();
    }
};