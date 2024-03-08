#pragma once

#include "../Math/Vec2.hpp"

#include <iostream>

class Physics
{
public:
  Physics();
  ~Physics();

	void update();

private:
	void collision();
};
