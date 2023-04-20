#pragma once

#include "../Math/Vec2.h"
#include "../Managers/EntityManager.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <iostream>
#include <string>

class Physics
{
public:
  Physics();
  ~Physics();

  Vec2 getOverlap(const int entityIdOne, const int entityIdTwo);
  Vec2 getPreviousOverlap(const int entityIdOne, const int entityIdTwo);

  bool isCollision(const int e1, const int e2);
  // bool isIntersect(Line l1, Line l2);
  // bool isInside(Vec2 v, Line l);

	void collision();
};
