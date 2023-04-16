#pragma once

#include "../Math/Vec2.h"

#include <string>
#include <iostream>

class Physics
{
public:
  Physics();
  ~Physics();

  Vec2 getOverlap(const size_t entityIdOne, const size_t entityIdTwo);
  Vec2 getPreviousOverlap(const size_t entityIdOne, const size_t entityIdTwo);

  bool isCollision(const size_t e1, const size_t e2);
  // bool isIntersect(Line l1, Line l2);
  // bool isInside(Vec2 v, Line l);
};
