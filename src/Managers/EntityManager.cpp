#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}

// private
EntityManager::EntityManager()
{
	createEntity();
}


void EntityManager::createEntity()
{
	ComponentMemoryPool& componentPool = ComponentMemoryPool::Instance();

	std::map<std::string, size_t> configMap = ConfigurationManager::Instance().getConfigs();

	const sf::Texture& texture = AssetManager::Instance().getAsset("wood");

	for(size_t i = 0; i < componentPool.getMaxCapacity(); i++)
	{
		std::srand(std::time(nullptr) + i);
		float randMax = RAND_MAX * 1.0f;
		float rPX     = std::rand() / randMax;
		float rPY     = std::rand() / randMax;
		float rSX     = std::rand() / randMax;
		float rSY     = std::rand() / randMax;
		float rVC     = std::rand() / randMax;
		float rRa     = std::rand() / randMax;

		size_t minS  = configMap.at("SMIN");
		size_t maxS  = configMap.at("SMAX");
		size_t minV  = configMap.at("VMIN");
		size_t maxV  = configMap.at("VMAX");
		size_t minR  = configMap.at("SRMIN");
		size_t maxR  = configMap.at("SRMAX");
		size_t minPX = minR;
		size_t maxPX = 640;
		size_t minPY = minR;
		size_t maxPY = 480;

		size_t randRad    = minR  + (rRa * (maxR  - minR));
		size_t randPosX   = minPX + (rPX * (maxPX - minPX));
		size_t randPosY   = minPY + (rPY * (maxPY - minPY));
 		size_t randSpeedX = minS  + (rSX * (maxS  - minS));
		size_t randSpeedY = minS  + (rSY * (maxS  - minS));
		size_t randVCount = minV  + (rVC * (maxV  - minV));

		size_t fR = configMap.at("FR");
		size_t fG = configMap.at("FG");
		size_t fB = configMap.at("FB");
		size_t oR = configMap.at("OR");
		size_t oG = configMap.at("OG");
		size_t oB = configMap.at("OB");
		size_t oT = configMap.at("OT");
		size_t tL = configMap.at("TL");

		sf::Color fill    = sf::Color(fR, fG, fB);
		sf::Color outline = sf::Color(oR, oG, oB);

		componentPool.addComponent<CTransform>(i, Vec2(randPosX,randPosY), Vec2(randSpeedX, randSpeedY), false);
		componentPool.addComponent<CShape>(i, randRad, randVCount, randPosX, randPosY, fill, outline, oT, texture,  false);
		componentPool.addComponent<CCollision>(i, randRad,  false);
		componentPool.addComponent<CLifespan>(i, tL, false);
	}
}