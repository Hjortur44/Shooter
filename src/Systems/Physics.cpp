#include "Physics.h"

Physics::Physics() {}

Physics::~Physics() {}

void Physics::update()
{
/*
	EntityComponentsManager& compManager = EntityComponentsManager::Instance();
	Entity            player      = compManager.player();
	CBoundingBox&     pBox        = player.getComponent<CBoundingBox>();
	CCollision&       pColl       = player.getComponent<CCollision>();
	CController&      pCont       = player.getComponent<CController>();
	CTransform&       pTrans      = player.getComponent<CTransform>();
*/
}


const int Physics::collisionDistance(const Vec2& pLoc)
{
	return 0;
}
