#pragma once

#include "../Entities/Entity.h"
#include "../Managers/EntityComponentsManager.h"
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

	const int collisionDistance(const Vec2& pLoc);
};
