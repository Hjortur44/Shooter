#pragma once

#include "Movement.h"
#include "../Entities/Entity.h"
#include "../Managers/EntityManager.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <string>

class Physics
{
public:
  Physics();
  ~Physics();

	void update();

private:
	void collision(const Vec2& playerPosition, const Vec2& playerHalfDimension,
								const Vec2& opponentPosition, const Vec2& opponentHalfDimension);

	void outside();
	void thrust();

	Movement m_movement;
};
