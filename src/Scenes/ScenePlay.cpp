#include "ScenePlay.h"

ScenePlay::ScenePlay() : Scene()
{
	EntityComponentsManager::Instance().registerType("Map");
	m_spawner.spawnPlayer();
	m_spawner.spawnEnemy();
	m_spawner.spawnEnemy();
	m_spawner.spawnEnemy();
	m_spawner.spawnEnemy();
}

ScenePlay::~ScenePlay() {}

void ScenePlay::update() {}

void ScenePlay::mapNumber(const int number)
{
	AssetManager&            assManager = AssetManager::Instance();
 	EntityComponentsManager& ecManager  = EntityComponentsManager::Instance();
 	MapManager&              mapManager = MapManager::Instance();

	Vec2 vel;

	for(const auto& [key, value] : mapManager.mapTexturesAndLocations(number))
	{
		for(const Vec2& v : value)
		{
			Entity e = ecManager.addEntity("Map");
			e.modifyComponent<CBoundingBox>(true);
			e.modifyComponent<CLifespan>(0, true);
			e.modifyComponent<CTexture>(assManager.getAsset(key), true);
			e.modifyComponent<CTransform>(v, vel, true);
		}
	}
}