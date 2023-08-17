#include "Scene_Play.h"

Scene_Play::Scene_Play() : Scene()
{
	EntityComponentsManager::Instance().registerType("Map");
	m_spawner.spawnPlayer();
}

Scene_Play::~Scene_Play() {}

void Scene_Play::update() {}

void Scene_Play::mapNumber(const int number)
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