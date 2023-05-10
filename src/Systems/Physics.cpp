#include "Physics.h"

Physics::Physics() {}
Physics::~Physics() {}

void Physics::update()
{
	EntityManager& manager = EntityManager::Instance();

	for(Entity p : manager.entitiesByType("Player"))
	{
		CBoundingBox& pbox = p.getComponent<CBoundingBox>();
		CTransform& ptrans = p.getComponent<CTransform>();

		bool bulletHit = isPlayerDead("Bullet", pbox, ptrans);
		bool enemyHit  = isPlayerDead("Enemy", pbox, ptrans);

	//	if(bulletHit || enemyHit)
		//	manager.removeEntity("Player", p);
	}
}

// private
bool Physics::isPlayerDead(const std::string& type, CBoundingBox& pbox, CTransform& ptrans)
{
	EntityManager& manager = EntityManager::Instance();
	bool isDead = false;

	for(Entity e : manager.entitiesByType(type))
	{
		CBoundingBox& ebox = e.getComponent<CBoundingBox>();
		CTransform& etrans = e.getComponent<CTransform>();

		bool out = outside(etrans.position, ebox.dimension);
		bool coll = collision(ptrans.position, pbox.halfDimension,
													 etrans.position, ebox.halfDimension);

		if(coll)
		{
			//manager.removeEntity(type, e);
			isDead = true;
		}
		else if(out)
		{
			manager.removeEntity(type, e);
		}
	}

	return isDead;
}


bool Physics::collision(const Vec2& pPos, const Vec2& pHDim,
								const Vec2& oPos, const Vec2& oHDim)
{
	Vec2 radiusSumSQ = (pHDim + oHDim) * (pHDim + oHDim);
	Vec2 distSQ = (pPos - oPos) * (pPos - oPos);

	// Overlaps
	bool hor = distSQ.y < radiusSumSQ.x;
	bool ver = distSQ.x < radiusSumSQ.y;

	return hor && ver;
}


bool Physics::outside(const Vec2& pos, const Vec2& dim)
{
	Vec2 window(640, 480); // the values need to be derived in better way.

	bool hor = (pos.y + dim.y) < 0 || (pos.y - dim.y) > window.y;
	bool ver = (pos.x + dim.x) < 0 || (pos.x - dim.x) > window.x;

	return hor || ver;
}