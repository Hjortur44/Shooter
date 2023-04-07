#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


const std::map<size_t, std::vector<size_t>>& EntityManager::getEntities() const
{
	return m_entities;
}


// private
EntityManager::EntityManager()
{
	m_configMap = m_configManager.getConfigs();

	createEntity();
}


void EntityManager::createEntity()
{
	ComponentMemoryPool& pool = ComponentMemoryPool::Instance();

	for(size_t i = 0; i < pool.getMaxCapacity(); i++)
	{
		std::srand(std::time(nullptr) + i);
		float randMax = RAND_MAX * 1.0f;
		float rPX     = std::rand() / randMax;
		float rPY     = std::rand() / randMax;
		float rSX     = std::rand() / randMax;
		float rSY     = std::rand() / randMax;
		float rVC     = std::rand() / randMax;
		float rRa     = std::rand() / randMax;

		size_t minS  = m_configMap.at("SMIN");
		size_t maxS  = m_configMap.at("SMAX") - minS;
		size_t minV  = m_configMap.at("VMIN");
		size_t maxV  = m_configMap.at("VMAX") - minV;
		size_t minR  = m_configMap.at("SRMIN");
		size_t maxR  = m_configMap.at("SRMAX") - minR;
		size_t minPX = minR;
		size_t maxPX = 640 - minPX;
		size_t minPY = minR;
		size_t maxPY = 480 - minPY;

		size_t randRad    = minR  + (rRa * maxR);
		size_t randPosX   = minPX + (rPX * maxPX);
		size_t randPosY   = minPY + (rPY * maxPY);
 		size_t randSpeedX = minS  + (rSX * maxS);
		size_t randSpeedY = minS  + (rSY * maxS);
		size_t randVCount = minV  + (rVC * maxV);

		size_t fR = m_configMap.at("FR");
		size_t fG = m_configMap.at("FG");
		size_t fB = m_configMap.at("FB");
		size_t oR = m_configMap.at("OR");
		size_t oG = m_configMap.at("OG");
		size_t oB = m_configMap.at("OB");
		size_t oT = m_configMap.at("OT");
		size_t tL = m_configMap.at("TL");

		std::vector<size_t> entity;
		entity.push_back(randPosX);
		entity.push_back(randPosY);
		entity.push_back(randSpeedX);
		entity.push_back(randSpeedY);
		entity.push_back(randRad);
		entity.push_back(randVCount);
		entity.push_back(m_configMap.at("FR"));
		entity.push_back(m_configMap.at("FG"));
		entity.push_back(m_configMap.at("FB"));
		entity.push_back(m_configMap.at("OR"));
		entity.push_back(m_configMap.at("OG"));
		entity.push_back(m_configMap.at("OB"));
		entity.push_back(m_configMap.at("OT"));
		entity.push_back(m_configMap.at("TL"));

		entity.push_back(pool.getFreeId());

		m_entities[i] = entity;
	}
}