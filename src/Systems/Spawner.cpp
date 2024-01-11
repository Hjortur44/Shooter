#include "Spawner.hpp"

Spawner::Spawner() {}

Spawner::~Spawner() {}

void Spawner::spawnBullet(const int mouseX, const int mouseY)
{
/*
	AssetManager&            assManager = AssetManager::Instance();
	EntityComponentsManager& ecManager  = EntityComponentsManager::Instance();

	std::string type = "Bullet";

	ecManager.registerType(type);

	Vec2 position = {mouseX * 1.0f, mouseY * 1.0f};
	Vec2 velocity = {3.0f, 3.0f};

	Entity e = ecManager.addEntity(type);
	e.modifyComponent<CBoundingBox>(true);
	e.modifyComponent<CLifespan>(1, true);
	e.modifyComponent<CTexture>(assManager.getAsset("marble"), true);
	e.modifyComponent<CTransform>(position, velocity, true);
*/
}


void Spawner::spawnEnemy()
{
/*
	AssetManager&            assManager = AssetManager::Instance();
	EntityComponentsManager& ecManager  = EntityComponentsManager::Instance();

	std::string type = "Enemy";

	m_enemyCount++;

	ecManager.registerType(type);

	Vec2 position = {m_enemyCount * 64.0f, m_enemyCount * 64.0f};
	Vec2 velocity = {3.0f, 3.0f};

	Entity e = ecManager.addEntity(type);
	e.modifyComponent<CBoundingBox>(true);
	e.modifyComponent<CLifespan>(1, true);
	e.modifyComponent<CTexture>(assManager.getAsset("brick"), true);
	e.modifyComponent<CTransform>(position, velocity, true);
*/
}


void Spawner::spawnPlayer()
{
	Vec2 position = {0.0f, 10.0f};
	Vec2 velocity = {3.0f, 3.0f};

	EntityManager& ecManager = EntityManager::Instance();
	Entity e = ecManager.addEntity();

	CSprite& sp = ecManager.getComponentForEntity<CSprite>(e);

	AssetManager& assManager = AssetManager::Instance();
	sp.sprite.setTexture(assManager.getAsset("marble"));
	sp.isActive = true;

	ecManager.modifyComponent<CBoundingBox>(e, true);
	ecManager.modifyComponent<CLifespan>(e, 1, true);
	ecManager.modifyComponent<CTransform>(e, position, velocity, true);
}


void Spawner::update(const int number) {}