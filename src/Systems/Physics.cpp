#include "Physics.h"

Physics::Physics() {}

Physics::~Physics() {}

void Physics::update()
{
	EntityComponentsManager& ecManager = EntityComponentsManager::Instance();

	std::vector<Entity> allPlayers = EntityComponentsManager::Instance().entitiesByType("Player");

	Vec2 min(1.0f, 1.0f);
	Vec2 max(32.0f, 32.0f);

	if(!allPlayers.empty())
	{
		Entity player = allPlayers.at(0);
		CTransform&   transPlayer = player.getComponent<CTransform>();


		for(Entity bullet : ecManager.entitiesByType("Bullet"))
		{
			CTransform& transBullet = bullet.getComponent<CTransform>();

			Vec2 delta = transPlayer.currentPosition - transBullet.currentPosition;

			if(delta > min && delta < max)
				ecManager.removeEntity("Bullet", bullet);
		}


		for(Entity enemy : ecManager.entitiesByType("Enemy"))
		{
			CTransform&   transEnemy = enemy.getComponent<CTransform>();

			Vec2 delta = transPlayer.currentPosition - transEnemy.currentPosition;

			if(delta > min && delta < max)
				ecManager.removeEntity("Enemy", enemy);
		}
	}
}