#include "Spawner.h"

Spawner::Spawner() {}

Spawner::~Spawner() {}

void Spawner::spawnBullet(const int mouseX, const int mouseY)
{
	std::string type = "Bullet";

	Vec2 position = {0.0f, 100.0f};
	Vec2 velocity = {3.0f, 3.0f};

	EntityComponentsManager::Instance().registerType(type);

	Entity e = EntityComponentsManager::Instance().addEntity(type);
	e.modifyComponent<CBoundingBox>(true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}


void Spawner::spawnEnemy()
{
	std::string type = "Enemy";

	Vec2 position = {0.0f, 0.0f};
	Vec2 velocity = {3.0f, 3.0f};

	EntityComponentsManager::Instance().registerType(type);

	Entity e = EntityComponentsManager::Instance().addEntity(type);
	e.modifyComponent<CBoundingBox>(true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTransform>(position, velocity, true);
}


void Spawner::spawnPlayer()
{
	std::string type = "Player";

	Vec2 position = {100.0f, 100.0f};
	Vec2 velocity = {3.0f, 3.0f};

	AssetManager&            assManager = AssetManager::Instance();
	EntityComponentsManager& ecManager = EntityComponentsManager::Instance();

	ecManager.registerType(type);

	Entity e = ecManager.addEntity(type);
	e.modifyComponent<CBoundingBox>(true);
	e.modifyComponent<CLifespan>(0, true);
	e.modifyComponent<CTexture>(assManager.getAsset("marble"), true);
	e.modifyComponent<CTransform>(position, velocity, true);
}