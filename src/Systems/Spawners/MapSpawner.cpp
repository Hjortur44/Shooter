#include "MapSpawner.hpp"

MapSpawner::MapSpawner() {}

MapSpawner::~MapSpawner() {}

void MapSpawner::update(const int number)
{
	for(const auto& [key, value] : MapManager::Instance().textures(number))
	{
		for(size_t i = 0; i < value.size(); i += 2)
		{
			Entity e = EntityManager::Instance().addEntity();

			CSprite& sp =	e.getComponent<CSprite>();
			sp.sprite.setTexture(AssetManager::Instance().textures(key));
			sp.sprite.setPosition(value.at(i + 1), value.at(i));
			sp.activate(true);
		}
	}

	EntityManager::Instance().update();
}