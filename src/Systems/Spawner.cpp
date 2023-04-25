#include "Spawner.h"

Spawner::Spawner() {}

Spawner::~Spawner() {}

void Spawner::spawnEntity(const std::string& type)
{
  std::vector<size_t> conf = ConfigurationManager::Instance().getConfigs(type);
	size_t radius    = conf.at(0);
	size_t vertices  = conf.at(1);
	size_t positionX = conf.at(2);
	size_t positionY = conf.at(3);
	size_t speed     = conf.at(4);
	size_t lifespan  = conf.at(5);

	Vec2 shape    = Vec2(radius, vertices);
	Vec2 position = Vec2(positionX, positionY);
	Vec2 velocity = Vec2(speed, speed);

	const sf::Texture& texture = AssetManager::Instance().getAsset("wood");

	Entity e;

	if(type == "Player")
		e = EntityManager::Instance().addPlayer();
	else
		e = EntityManager::Instance().addEntity();

	e.modifyComponent<CShape>(shape, position, texture, true);
	e.modifyComponent<CTransform>(position, velocity, true);
	e.modifyComponent<CLifespan>(lifespan, true);
}
