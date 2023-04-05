#include "Spawner.h"

Spawner::Spawner()
{
	m_configMap = m_configManager.getConfigs();

}

Spawner::~Spawner() {}


void Spawner::spawnEntity(const std::string& name)
{
	init(name);
}


// private
void Spawner::init(const std::string& name)
{
  const size_t id = m_compPool.activateSpot(name);

	const std::string& asset = m_assetManager.getAssets().at("wood");
	m_texture.loadFromFile(asset); // <<-- move this to the Asset class...

  if(id < m_compPool.getMaxCapacity())
  {
		m_compPool.addComponent<CTransform>(id);
		m_compPool.addComponent<CShape>(id);
		m_compPool.addComponent<CCollision>(id);
		m_compPool.addComponent<CLifespan>(id);

    auto& trans = m_compPool.getComponent<CTransform>(id);
    auto& shape = m_compPool.getComponent<CShape>(id);
    auto& coll  = m_compPool.getComponent<CCollision>(id);
    auto& life  = m_compPool.getComponent<CLifespan>(id);

		std::srand(std::time(nullptr) + id);
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
		size_t minPY = minR;
		size_t maxPX = 640 - minPX;
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

 		trans.currentPosition = Vec2(randPosX, randPosY);
    trans.velocityRandom  = Vec2(randSpeedX, randSpeedY);
    trans.angle           = 0;

    coll.radius = randRad;
    life.total = tL;

		shape.texture   = m_texture;
    shape.radius    = randRad;
		shape.points    = randVCount;
    shape.fill      = sf::Color(fR, fG, fB);
    shape.outline   = sf::Color(oR, oG, oB);
    shape.thickness = oT;
    shape.position  = trans.currentPosition;
  }
}