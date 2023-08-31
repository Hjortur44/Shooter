#pragma once

#include "../Managers/EntityComponentsManager.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <map>
#include <vector>

class Physics
{
public:
  Physics();
  ~Physics();

	void update();
};
