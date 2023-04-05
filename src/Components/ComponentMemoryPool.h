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
    std::vector<std::string> m_tags       = {""};
    ComponentVectors         m_compVecs;

    ComponentMemoryPool();

  public:
    ComponentMemoryPool(ComponentMemoryPool&) = delete;

    static ComponentMemoryPool& Instance();

		const bool isActive(const size_t id) const;

    const size_t getMaxCapacity() const;
		const size_t activateSpot(const std::string& tag);

		void deactivateSpot(const size_t id);

    template <typename T>
    T& getComponent(const size_t id)
    {
			return std::get<std::vector<T>>(m_compVecs).at(id);
    }

    template <typename T>
    void addComponent(const size_t id)
    {
			if(m_actives.at(id))
			{
	    	auto& comp = std::get<std::vector<T>>(m_compVecs).at(id);
	    	comp.active = true;
			}
    }

    template <typename T>
    void removeComponent(const size_t id)
    {
      auto& comp = std::get<std::vector<T>>(m_compVecs).at(id);
			comp.active = false;
			comp = T();
    }
};