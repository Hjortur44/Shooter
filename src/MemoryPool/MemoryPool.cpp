#include "MemoryPool.hpp"

MemoryPool& MemoryPool::Instance()
{
  static MemoryPool INSTANCE(500);
  return INSTANCE;
}


const size_t MemoryPool::activateEntity()
{
	size_t id = 0;

	for(size_t i = 1; i < m_actives.size(); i++)
	{
		if(!m_actives[i])
		{
			id = i;
			m_actives[i] = true;
			break;
		}
	}

	return id;
}


void MemoryPool::deactivateEntity(const size_t id)
{
	if(id < m_actives.size())
		m_actives.at(id) = false;
}


// private
MemoryPool::MemoryPool(const size_t poolSize)
{
  auto& box   = std::get<std::vector<CBoundingBox>>(m_compVecs);
  auto& life  = std::get<std::vector<CLifespan>>(m_compVecs);
  auto& sp    = std::get<std::vector<CSprite>>(m_compVecs);
  auto& trans = std::get<std::vector<CTransform>>(m_compVecs);

  for(size_t i = 0; i < poolSize; i++)
  {
    box.push_back(CBoundingBox());
    life.push_back(CLifespan());
    sp.push_back(CSprite());
	  trans.push_back(CTransform());

    m_actives.push_back(false);
  }
}