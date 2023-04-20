#include "Physics.h"

Physics::Physics() {}
Physics::~Physics() {}

void Physics::collision()
{
	const int size = ComponentMemoryPool::Instance().getMaxCapacity();

	for(int i = 0; i < size; i++)
	{
	  CBoundingBox& bb0  = ComponentMemoryPool::Instance().getComponent<CBoundingBox>(i);
		CCollision& coll0  =  ComponentMemoryPool::Instance().getComponent<CCollision>(i);
		CShape& shape0     = ComponentMemoryPool::Instance().getComponent<CShape>(i);

		Vec2 pos0(shape0.circle.getPosition().x, shape0.circle.getPosition().y);

		for(int j = 0; j < size; j++)
		{
  		CBoundingBox& bb1  = ComponentMemoryPool::Instance().getComponent<CBoundingBox>(j);
			CShape& shape1     = ComponentMemoryPool::Instance().getComponent<CShape>(j);

			Vec2 pos1(shape1.circle.getPosition().x, shape1.circle.getPosition().y);

			bool hasCollide0 = coll0.isCollision(pos0, pos1, bb0.halfDimension, bb1.halfDimension);

			if(hasCollide0)
			{
				EntityManager::Instance().removeBullet(j);
				EntityManager::Instance().removeBullet(i);
			}
		}
	}
}