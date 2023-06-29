#pragma once

#include "../Entities/Entity.h"
#include "../Managers/ComponentManager.h"
#include "../Math/Vec2.h"

#include <cstddef>

class Movement
{
public:
  Movement();
  ~Movement();

  void update();

private:
	void playerMovement(CCollision& coll, CController& cont);
	void oneKey(CCollision& coll, CController& cont);
	void twoKeys(CCollision& coll, CController& cont);
	void threeKeys(CCollision& coll, CController& cont);

  Vec2 m_dig = {0.707106781f, 0.707106781f};

  Vec2 m_d = {0.0f, 1.0f};
  Vec2 m_l = {-1.0f, 0.0f};
  Vec2 m_r = {1.0f, 0.0f};
  Vec2 m_u = {0.0f, -1.0f};
};
