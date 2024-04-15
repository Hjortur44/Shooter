#include "EntitySpawner.hpp"

EntitySpawner::EntitySpawner() {}

EntitySpawner::~EntitySpawner() {}

void EntitySpawner::spawnBullet(const int mouseX, const int mouseY) {}

void EntitySpawner::spawnEnemy() {}

void EntitySpawner::spawnPlayer()
{
	Entity e = EntityManager::Instance().addEntity();

	e.getComponent<CDirection>().activate(true);

	CSprite& sp =	e.getComponent<CSprite>();
	sp.sprite.setTexture(AssetManager::Instance().textures("brick"));
	sp.sprite.setPosition(10.0f, 10.0f);
	sp.activate(true);

	EntityManager::Instance().update();
}

void EntitySpawner::update(const int number)
{
	spawnPlayer();
}