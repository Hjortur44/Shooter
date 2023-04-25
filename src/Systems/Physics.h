#pragma once

#include "Movement.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <string>

class Physics
{
public:
  Physics();
  ~Physics();

	void collision();
	void outside();

private:
	Movement m_movement;
};
