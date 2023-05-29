#include "Physics.h"

Physics::Physics() {}

Physics::~Physics() {}

void Physics::update()
{
	ComponentManager& compManager = ComponentManager::Instance();
	Entity            player      = compManager.player();
	CBoundingBox&     pBox        = player.getComponent<CBoundingBox>();
	CController&      pCont       = player.getComponent<CController>();
	CTransform&       pTrans      = player.getComponent<CTransform>();

	pTrans.previousPosition = pTrans.currentPosition;
	pTrans.currentPosition += (pTrans.velocity * pCont.direction);

	int coll = borderWallCollision(pTrans.currentPosition, pBox.dimension);

	switch(coll)
	{
		case 0:
			pTrans.currentPosition = pTrans.previousPosition;
		break;
		case 1:
			pTrans.currentPosition.x = pTrans.previousPosition.x;
		break;
		case 2:
			pTrans.currentPosition.y = pTrans.previousPosition.y;
		break;
	}
}


int Physics::borderWallCollision(const Vec2& pPosition, const Vec2& pDimension)
{
	ComponentManager& compManager = ComponentManager::Instance();
	int coll = -1;

	for(Entity wall : compManager.entitiesByType("Wall"))
	{
		CBoundingBox& wBox   = wall.getComponent<CBoundingBox>();
		CTransform&   wTrans = wall.getComponent<CTransform>();

		Vec2 pOrigin = pPosition + (pDimension / 2.0f);
		Vec2 center = ((Vec2(640.0f, 480.0f) - 32.0f) / 2.0f) + (pDimension / 2.0f);
		Vec2 centerSQ = (center - 48.0f) * (center - 48.0f);
		Vec2 deltaSQ = (pOrigin - center) * (pOrigin - center);
		Vec2 distSQ = centerSQ - deltaSQ;

		if(distSQ < 0)
			coll = 0;
		else if(distSQ.x < 0)
			coll = 1;
		else if(distSQ.y < 0)
			coll = 2;
	}

	return coll;
}