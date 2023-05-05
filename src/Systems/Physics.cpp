#include "Physics.h"

Physics::Physics() {}
Physics::~Physics() {}

void Physics::update()
{
	EntityManager& manager = EntityManager::Instance();

	const std::vector<Entity> pp = manager.entitiesByType("Player");
	const std::vector<Entity> bb = manager.entitiesByType("Bullet");

	for(Entity p : pp)
	{
		CBoundingBox& pbox = p.getComponent<CBoundingBox>();
		CTransform& ptrans = p.getComponent<CTransform>();

		bool o = outside(ptrans.position, pbox.dimension);

		for(Entity b : bb)
		{
			CBoundingBox& bbox = b.getComponent<CBoundingBox>();
			CTransform& btrans = b.getComponent<CTransform>();

			bool out = outside(btrans.position, bbox.dimension);
			bool coll = collision(ptrans.position, pbox.halfDimension,
														 btrans.position, bbox.halfDimension);

			if(coll)
			{
				manager.removeEntity("Bullet", b);
				manager.removeEntity("Player", p);
			}
			else if(out)
			{
				manager.removeEntity("Bullet", b);
			}
		}
	}
}

// private
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