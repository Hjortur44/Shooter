#include "Spawner.h"

Spawner::Spawner(const int baseSize) : m_baseSize(baseSize) {}

Spawner::~Spawner() {}

void Spawner::spawnBullet(const int mouseX, const int mouseY)
{
  const std::vector<int>& conf = ConfigurationManager::Instance().getEntityConfigs("Bullet");

	std::string textureName = "wood_32_32";

	Vec2 position = Vec2(conf.at(0), conf.at(1)) * m_baseSize; // remove this later, as the bullets have dynamic start location.

	int speed    = conf.at(2);
	int lifespan = conf.at(3);

	Entity p = ComponentManager::Instance().player();
	CTransform& t =	p.getComponent<CTransform>();

	float a  = t.currentPosition.x - mouseX;
	float b  = t.currentPosition.y - mouseY;
	float th = atan2f(b, a);
	float x  = std::cos(th) * (-1);
	float y  = std::sin(th) * (-1);

	Vec2 shape    = Vec2(m_baseSize, m_baseSize);
	Vec2 velocity = Vec2(x * speed, y * speed);

	Entity e = ComponentManager::Instance().addEntity("Bullet");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(t.currentPosition, velocity, true);
}


void Spawner::spawnEnemy()
{
  const std::vector<int>& conf = ConfigurationManager::Instance().getEntityConfigs("Enemy");

	std::string textureName = "wood_32_32";

	Vec2 position = Vec2(conf.at(0), conf.at(1)) * m_baseSize;

	int speed    = conf.at(2);
	int lifespan = conf.at(3);

	Vec2 shape    = Vec2(m_baseSize, m_baseSize);
	Vec2 velocity = Vec2(speed, speed);

	Entity e = ComponentManager::Instance().addEntity("Enemy");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}


void Spawner::spawnPlayer()
{
  const std::vector<int>& conf = ConfigurationManager::Instance().getEntityConfigs("Player");

	std::string textureName = "wood_32_32";

	Vec2 position = Vec2(conf.at(0), conf.at(1)) * m_baseSize;

	int speed    = conf.at(2);
	int lifespan = conf.at(3);

	Vec2 shape    = Vec2(m_baseSize, m_baseSize);
	Vec2 velocity = Vec2(speed, speed);

	Entity e = ComponentManager::Instance().addEntity("Player");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CController>(0, true);
	e.modifyComponent<CLifespan>(lifespan, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}

void Spawner::spawn()
{
	std::string textureName = "brick_640_32";

	Vec2 position(0.0f, 0.0f);

	Vec2 shape(640.0f, 32.0f);
	Vec2 velocity(0.0f, 0.0f);

	Entity e = ComponentManager::Instance().addEntity("Wall");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);


	position = {0.0f, 480.0f-32};

	e = ComponentManager::Instance().addEntity("Wall");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);


	textureName = "brick_32_480";

	position = {0.0f, 32.0f};
	shape = {32.0f, 480.0f};

	e = ComponentManager::Instance().addEntity("Wall");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);


	position = {640.0f-32, 32.0f};

	e = ComponentManager::Instance().addEntity("Wall");
	e.modifyComponent<CBoundingBox>(shape, true, true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTexture>(textureName, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}