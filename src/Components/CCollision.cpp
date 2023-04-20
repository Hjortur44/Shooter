#include "Components.h"

CCollision::CCollision() {}
CCollision::CCollision(bool active) : active(active) {}

const bool CCollision::isCollision(const Vec2& posShapeA, const Vec2& posShapeB,
																	 const Vec2& halfDimBoxA, const Vec2& halfDimBoxB)
{
	bool collision = false;

	if(active)
	{
		Vec2 a = posShapeA + halfDimBoxA;
		Vec2 b = posShapeB + halfDimBoxB;

		Vec2 diff = (posShapeA + halfDimBoxA) - (posShapeB + halfDimBoxB);
		Vec2 sum  = halfDimBoxA + halfDimBoxB;
		Vec2 dist = diff - sum;

		int distX = dist.x * dist.x;
		int distY = dist.y * dist.y;

		int sumX = sum.x * sum.x;
		int sumY = sum.y * sum.y;

		// Overlaps
		bool hor = distY < sumX;
		bool ver = distX < sumY;

		collision = hor && ver;
	}

	return collision;
}
