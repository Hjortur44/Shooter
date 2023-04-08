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


void ComponentMemoryPool::activateNext()
{
  if(m_counter < MAX_CAPACITY)
  {
    getComponent<CShape>(m_counter++).active = true;
  }
}


void ComponentMemoryPool::freeUpId()
{
	getComponent<CShape>(m_counter).active = false;

  if(m_counter > 0)
		m_counter--;
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
  }
}