#include "Spawner.h"

Spawner::Spawner() {}

Spawner::~Spawner() {}

void Spawner::spawnEntity(const std::string& type)
{
  const std::vector<size_t>& conf = ConfigurationManager::Instance().getConfigs(type);
	const sf::Texture& texture      = AssetManager::Instance().getAsset("wood");

	size_t radius    = conf.at(0);
	size_t vertices  = conf.at(1);
	size_t speed     = conf.at(2);
	size_t lifespan  = conf.at(3);

	Vec2 shape    = Vec2(radius, vertices);
	Vec2 position = Vec2(100, 100);
	Vec2 velocity = Vec2(speed, speed);

	Entity e = EntityManager::Instance().addEntity(type);
	e.modifyComponent<CBoundingBox>(Vec2(radius, radius), true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CShape>(shape, position, texture, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}

void Spawner::spawnBullet(const int mouseX, const int mouseY)
{
  const std::vector<size_t>& conf = ConfigurationManager::Instance().getConfigs("Bullet");
	const sf::Texture& texture      = AssetManager::Instance().getAsset("wood");

	size_t radius    = conf.at(0);
	size_t vertices  = conf.at(1);
	size_t speed     = conf.at(2);
	size_t lifespan  = conf.at(3);

	Entity p = EntityManager::Instance().player();
	CTransform& t =	p.getComponent<CTransform>();

	float a  = t.position.x - mouseX;
	float b  = t.position.y - mouseY;
	float th = atan2f(b, a);
	float x  = std::cos(th) * (-1);
	float y  = std::sin(th) * (-1);

	Vec2 shape    = Vec2(radius, vertices);
	Vec2 velocity = Vec2(x * speed, y * speed);

	Entity e = EntityManager::Instance().addEntity("Bullet");
	e.modifyComponent<CBoundingBox>(Vec2(radius, radius), true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CShape>(shape, t.position, texture, true);
	e.modifyComponent<CTransform>(t.position, velocity, true);
}