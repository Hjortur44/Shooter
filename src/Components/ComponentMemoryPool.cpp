#include "ComponentMemoryPool.h"

ComponentMemoryPool& ComponentMemoryPool::Instance()
{
  static ComponentMemoryPool INSTANCE;
  return INSTANCE;
}


const size_t ComponentMemoryPool::getMaxCapacity()
{
	return MAX_CAPACITY;
}


const size_t ComponentMemoryPool::getFreeId()
{
	for(size_t i = 0; i < m_actives.size(); i++)
  {
    if(!m_actives.at(i))
    {
      m_actives.at(i) = true;
			return i;
    }
  }

  return MAX_CAPACITY;
}


void ComponentMemoryPool::freeUpId(const size_t id)
{
	m_actives.at(id) = false;

  removeComponent<CBoundingBox>(id);
  removeComponent<CCollision>(id);
  removeComponent<CLifespan>(id);
  removeComponent<CShape>(id);
  removeComponent<CTransform>(id);
}


// private
ComponentMemoryPool::ComponentMemoryPool()
{
  auto& box   = getComponentVector<CBoundingBox>();
  auto& coll  = getComponentVector<CCollision>();
  auto& life  = getComponentVector<CLifespan>();
  auto& sh    = getComponentVector<CShape>();
  auto& trans = getComponentVector<CTransform>();

  for(size_t i = 0; i < MAX_CAPACITY; i++)
  {
    box.push_back(CBoundingBox());
    coll.push_back(CCollision());
    life.push_back(CLifespan());
    sh.push_back(CShape());
    trans.push_back(CTransform());

		m_actives.push_back(false);
  }
}