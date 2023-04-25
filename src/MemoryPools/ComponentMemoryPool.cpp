#include "ComponentMemoryPool.h"

ComponentMemoryPool& ComponentMemoryPool::Instance()
{
  static ComponentMemoryPool INSTANCE(500);
  return INSTANCE;
}


const std::vector<bool> ComponentMemoryPool::actives() const
{
  return m_actives;
}


const size_t ComponentMemoryPool::activateEntity()
{
	size_t id = 1;

	for(; id < m_poolSize - 1; id++)
	{
		if(!m_actives[id])
		{
			m_actives[id] = true;
			break;
		}
	}

	return id;
}


const size_t ComponentMemoryPool::activatePlayer()
{
	m_actives[0] = true;
	return 0;
}


const size_t ComponentMemoryPool::poolSize() const
{
  return m_poolSize - 1;
}


void ComponentMemoryPool::deactivateEntity(const size_t id)
{
	m_actives[id] = false;
}


// private
ComponentMemoryPool::ComponentMemoryPool(const size_t poolSize) : m_poolSize(poolSize)
{
  auto& box   = std::get<std::vector<CBoundingBox>>(m_compVecs);
  auto& coll  = std::get<std::vector<CCollision>>(m_compVecs);
  auto& life  = std::get<std::vector<CLifespan>>(m_compVecs);
  auto& sh    = std::get<std::vector<CShape>>(m_compVecs);
  auto& trans = std::get<std::vector<CTransform>>(m_compVecs);

  for(int i = 0; i < poolSize; i++)
  {
    box.push_back(CBoundingBox());
    coll.push_back(CCollision());
    life.push_back(CLifespan());
    sh.push_back(CShape());
    trans.push_back(CTransform());

    m_actives.push_back(false);
  }
}
