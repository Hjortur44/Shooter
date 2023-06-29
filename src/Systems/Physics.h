#pragma once

#include "../Entities/Entity.h"
#include "../Managers/ComponentManager.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <string>
#include <vector>

class Physics
{
public:
  Physics();
  ~Physics();

	void update();

	int borderWallCollision(const Vec2& pPosition, const Vec2& pDimension);
	int wallCollision(const Vec2& pPosition, const Vec2& pDimension);
};
