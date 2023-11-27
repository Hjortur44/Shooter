#pragma once

#include "../Math/Vec2.hpp"

class CTransform
{
public:
  CTransform();
  CTransform(const Vec2& position, const Vec2& velocity, bool activate);

  Vec2 currentPosition  = {0.0f, 0.0f};
  Vec2 previousPosition = {0.0f, 0.0f};
  Vec2 velocity         = {0.0f, 0.0f};

	bool isActive = false;

  int angle = 0;
};