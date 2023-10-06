#include "EnemyMovement.h"

EnemyMovement::EnemyMovement() {}

EnemyMovement::~EnemyMovement() {}

void EnemyMovement::update()
{
	EntityComponentsManager& ecManager = EntityComponentsManager::Instance();

	for(Entity ent : ecManager.entitiesByType("Enemy"))
	{
		CTransform& trans = ent.getComponent<CTransform>();
		trans.previousPosition = trans.currentPosition;
		trans.currentPosition += (trans.velocity);
	}
}