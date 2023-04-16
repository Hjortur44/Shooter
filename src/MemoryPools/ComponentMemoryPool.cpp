#include "ComponentMemoryPool.h"

ComponentMemoryPool& ComponentMemoryPool::Instance()
{
  static ComponentMemoryPool INSTANCE;
  return INSTANCE;
}


const std::vector<bool> ComponentMemoryPool::getActives() const
{
  return m_actives;
}


const bool ComponentMemoryPool::isActive(const size_t id) const
{
  return m_actives.at(id);
}


const size_t ComponentMemoryPool::getMaxCapacity() const
{
  return MAX_CAPACITY - 1;
}


const size_t ComponentMemoryPool::addEntity()
{
  size_t offset = MAX_CAPACITY - 1;

  for(size_t i = 0; i < offset; i++)
  {
    if(!m_actives[i])
    {
      m_actives[i] = true;
      return i;
    }
  }

  return offset;
}


void ComponentMemoryPool::removeEntity(const size_t id)
{
  if(id < MAX_CAPACITY)
  {
    m_actives.at(id) = false;
    std::get<std::vector<CBoundingBox>>(m_compVecs).at(id) = CBoundingBox();
    std::get<std::vector<CCollision>>(m_compVecs).at(id)   = CCollision();
    std::get<std::vector<CLifespan>>(m_compVecs).at(id)    = CLifespan();
    std::get<std::vector<CShape>>(m_compVecs).at(id)       = CShape();
    std::get<std::vector<CTransform>>(m_compVecs).at(id)   = CTransform();
  }
}


// private
ComponentMemoryPool::ComponentMemoryPool()
{
  auto& box   = std::get<std::vector<CBoundingBox>>(m_compVecs);
  auto& coll  = std::get<std::vector<CCollision>>(m_compVecs);
  auto& life  = std::get<std::vector<CLifespan>>(m_compVecs);
  auto& sh    = std::get<std::vector<CShape>>(m_compVecs);
  auto& trans = std::get<std::vector<CTransform>>(m_compVecs);

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
