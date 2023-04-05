#include "ComponentMemoryPool.h"

ComponentMemoryPool& ComponentMemoryPool::Instance()
{
  static ComponentMemoryPool INSTANCE;
  return INSTANCE;
}


const bool ComponentMemoryPool::isActive(const size_t id) const
{
	return m_actives.at(id);
}


const size_t ComponentMemoryPool::getMaxCapacity() const
{
  return MAX_CAPACITY;
}


const size_t ComponentMemoryPool::activateSpot(const std::string& tag)
{
	for(size_t i = 0; i < m_actives.size(); i++)
  {
    if(!m_actives.at(i))
    {
      m_tags.at(i)    = tag;
      m_actives.at(i) = true;
			return i;
    }
  }

  return MAX_CAPACITY;
}


void ComponentMemoryPool::deactivateSpot(const size_t id)
{
	if(id < MAX_CAPACITY)
	{
		m_tags.at(id)    = "";
		m_actives.at(id) = false;

		removeComponent<CTransform>(id);
		removeComponent<CLifespan>(id);
		removeComponent<CCollision>(id);
		removeComponent<CShape>(id);
		removeComponent<CBoundingBox>(id);
	}
}


// private
ComponentMemoryPool::ComponentMemoryPool()
{
  auto& trans = std::get<std::vector<CTransform>>(m_compVecs);
  auto& life  = std::get<std::vector<CLifespan>>(m_compVecs);
  auto& coll  = std::get<std::vector<CCollision>>(m_compVecs);
  auto& sh    = std::get<std::vector<CShape>>(m_compVecs);
  auto& box   = std::get<std::vector<CBoundingBox>>(m_compVecs);

  for(size_t i = 0; i < MAX_CAPACITY; i++)
  {
    trans.push_back(CTransform());
    life.push_back(CLifespan());
    coll.push_back(CCollision());
    sh.push_back(CShape());
    box.push_back(CBoundingBox());

		m_actives.push_back(false);
		m_tags.push_back("");
  }
}