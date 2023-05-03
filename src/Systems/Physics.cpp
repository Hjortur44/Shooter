#include "Physics.h"

Physics::Physics() {}
Physics::~Physics() {}

void Physics::update()
{
	thrust();
}

// private
void Physics::collision(const Vec2& playerPosition, const Vec2& playerHalfDimension,
								const Vec2& opponentPosition, const Vec2& opponentHalfDimension)
{
	Vec2 player   = playerPosition      + playerHalfDimension;
	Vec2 opponent = opponentPosition    + opponentHalfDimension;
	Vec2 sum      = playerHalfDimension + opponentHalfDimension;

	Vec2 diff = player - opponent;
	Vec2 dist = diff   - sum;

	Vec2 distSQ = dist * dist;
	Vec2 sumSQ  = sum  * sum;

	// Overlaps
	bool hor = distSQ.y < sumSQ.x;
	bool ver = distSQ.x < sumSQ.y;

	// hor && ver;
}


void Physics::outside()
{
	const Vec2 pos = {0, 0};
  const Vec2 dim = {0, 0};

	Vec2 window(500, 480);

	bool hor = (pos.x + dim.x) < 0 || (pos.x > window.x);
	bool ver = (pos.y + dim.y) < 0 || (pos.y > window.y);

	//hor || ver;
}


void Physics::thrust()
{
	for(Entity e : EntityManager::Instance().entities())
	{
		CTransform& trans = e.getComponent<CTransform>();
		trans.position += (trans.velocity * m_movement.playerMovement());
	}
}