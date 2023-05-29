#include "ComponentMemoryPool.h"

ComponentMemoryPool& ComponentMemoryPool::Instance()
{
  static ComponentMemoryPool INSTANCE(500);
  return INSTANCE;
}


const std::vector<bool>& ComponentMemoryPool::actives() const
{
  return m_actives;
}


const size_t ComponentMemoryPool::activateEntity()
{
	size_t id = 0;

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
  auto& box     = std::get<std::vector<CBoundingBox>>(m_compVecs);
	auto& cont    = std::get<std::vector<CController>>(m_compVecs);
  auto& life    = std::get<std::vector<CLifespan>>(m_compVecs);
  auto& texture = std::get<std::vector<CTexture>>(m_compVecs);
  auto& trans   = std::get<std::vector<CTransform>>(m_compVecs);

  for(int i = 0; i < poolSize; i++)
  {
    box.push_back(CBoundingBox());
    cont.push_back(CController());
    life.push_back(CLifespan());
    texture.push_back(CTexture());
    trans.push_back(CTransform());

    m_actives.push_back(false);
  }
}
