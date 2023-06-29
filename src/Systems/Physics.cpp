#include "Physics.h"

Physics::Physics() {}

Physics::~Physics() {}

void Physics::update()
{
	ComponentManager& compManager = ComponentManager::Instance();
	Entity            player      = compManager.player();
	CBoundingBox&     pBox        = player.getComponent<CBoundingBox>();
	CCollision&       pColl       = player.getComponent<CCollision>();
	CController&      pCont       = player.getComponent<CController>();
	CTransform&       pTrans      = player.getComponent<CTransform>();

	int bwcoll = borderWallCollision(pTrans.currentPosition, pBox.halfDimension);
//	int wcoll = wallCollision(pTrans.currentPosition, pBox.halfDimension);

	pColl.collisionL = false;
	pColl.collisionR = false;
	pColl.collisionU = false;
	pColl.collisionD = false;

	switch(bwcoll)
	{
		case 2:
			pColl.collisionU = true;
			pTrans.currentPosition.y = pTrans.previousPosition.y;
		break;
		case 4:
			pColl.collisionD = true;
			pTrans.currentPosition.y = pTrans.previousPosition.y;
		break;
		case 8:
			pColl.collisionL = true;
			pTrans.currentPosition.x = pTrans.previousPosition.x;
		break;
		case 10:
			pColl.collisionL = true;
			pColl.collisionU = true;
			pTrans.currentPosition = pTrans.previousPosition;
		break;
		case 12:
			pColl.collisionD = true;
			pColl.collisionL = true;
			pTrans.currentPosition = pTrans.previousPosition;
		break;
		case 16:
			pColl.collisionR = true;
			pTrans.currentPosition.x = pTrans.previousPosition.x;
		break;
		case 18:
			pColl.collisionR = true;
			pColl.collisionU = true;
			pTrans.currentPosition = pTrans.previousPosition;
		break;
		case 20:
			pColl.collisionD = true;
			pColl.collisionR = true;
			pTrans.currentPosition = pTrans.previousPosition;
		break;
	}
}


int Physics::borderWallCollision(const Vec2& pPosition, const Vec2& pHalfDimension)
{
	ComponentManager& compManager = ComponentManager::Instance();

	int count = 2;
	int index = 0;
	int v[4] = {0, 0, 0, 0};

	for(Entity wall : compManager.entitiesByType("BorderWall"))
	{
		CBoundingBox& wBox   = wall.getComponent<CBoundingBox>();
		CTransform&   wTrans = wall.getComponent<CTransform>();

		Vec2 pOrigin = pPosition + pHalfDimension;
		Vec2 wOrigin = wTrans.currentPosition + wBox.halfDimension;
		Vec2 dimSumsSQ = (pHalfDimension + wBox.halfDimension) * (pHalfDimension + wBox.halfDimension);
		Vec2 deltaSQ = (pOrigin - wOrigin) * (pOrigin - wOrigin);
		Vec2 distSQ  = (deltaSQ - dimSumsSQ) * (deltaSQ - dimSumsSQ);

		if(distSQ.x < 48000.0f || distSQ.y < 48000.0f)
			v[index] = count;

		index++;
		count += count;
	}

	return v[0] + v[1] + v[2] + v[3];
}


int Physics::wallCollision(const Vec2& pPosition, const Vec2& pHalfDimension)
{
	ComponentManager& compManager = ComponentManager::Instance();
	int coll = -1;

	for(Entity wall : compManager.entitiesByType("InnerWall"))
	{
		CBoundingBox& wBox   = wall.getComponent<CBoundingBox>();
		CTransform&   wTrans = wall.getComponent<CTransform>();

		Vec2 pOrigin = pPosition + pHalfDimension;
		Vec2 wOrigin = wTrans.currentPosition + wBox.halfDimension;
		Vec2 dimSumsSQ = (pHalfDimension + wBox.halfDimension) * (pHalfDimension + wBox.halfDimension);
		Vec2 deltaSQ = (pOrigin - wOrigin) * (pOrigin - wOrigin);
		Vec2 distSQ  = deltaSQ - dimSumsSQ;

		if(distSQ < 0)
			coll = 0;
	}

	return coll;
}