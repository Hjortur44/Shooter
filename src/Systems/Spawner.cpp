#include "Spawner.h"

Spawner::Spawner() {}

Spawner::~Spawner() {}

void Spawner::spawnBullet(const int mouseX, const int mouseY)
{
  const std::vector<size_t>& conf = ConfigurationManager::Instance().getEntityConfigs("Bullet");
	const sf::Texture& texture      = AssetManager::Instance().getAsset("wood");

	size_t radius   = conf.at(0);
	size_t vertices = conf.at(1);
	size_t speed    = conf.at(2);
	size_t lifespan = conf.at(3);

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


void Spawner::spawnEnemy()
{
  const std::vector<size_t>& conf = ConfigurationManager::Instance().getEntityConfigs("Enemy");
	const sf::Texture& texture      = AssetManager::Instance().getAsset("wood");

	size_t radius   = conf.at(0);
	size_t vertices = conf.at(1);
	size_t speed    = conf.at(2);
	size_t lifespan = conf.at(3);

	Vec2 shape    = Vec2(radius, vertices);
	Vec2 position = Vec2(100, 100);
	Vec2 velocity = Vec2(speed, speed);

	Entity e = EntityManager::Instance().addEntity("Enemy");
	e.modifyComponent<CBoundingBox>(Vec2(radius, radius), true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CShape>(shape, position, texture, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}


void Spawner::spawnPlayer()
{
  const std::vector<size_t>& conf = ConfigurationManager::Instance().getEntityConfigs("Player");
	const sf::Texture& texture      = AssetManager::Instance().getAsset("brick");

	size_t radius   = conf.at(0);
	size_t vertices = conf.at(1);
	size_t speed    = conf.at(2);
	size_t lifespan = conf.at(3);

	Vec2 shape    = Vec2(radius, vertices);
	Vec2 position = Vec2(100, 100);
	Vec2 velocity = Vec2(speed, speed);

	Entity e = EntityManager::Instance().addEntity("Player");
	e.modifyComponent<CBoundingBox>(Vec2(radius, radius), true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CShape>(shape, position, texture, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}


void Spawner::spawnOuterWall()
{
  const std::vector<Vec2>& conf = ConfigurationManager::Instance().getAssetConfigs("Outer_wall");
	const sf::Texture& texture    = AssetManager::Instance().getAsset("brick");

	Vec2 shape(32.0f, 32.0f);
	Vec2 sOrigin = shape / 2;
	Vec2 vel(0.0f, 0.0f);

	for(const Vec2& pos : conf)
	{
		Vec2 position = (pos * shape) + sOrigin;
		Entity e = EntityManager::Instance().addEntity("Outer_wall");
		e.modifyComponent<CBoundingBox>(shape, true);
		e.modifyComponent<CShape>(shape, position, texture, true);
		e.modifyComponent<CTransform>(position, vel, true);
	}
}
