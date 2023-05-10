#pragma once

#include "../Entities/Entity.h"
#include "../Managers/EntityManager.h"
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

private:
	bool collision(const Vec2& pPos, const Vec2& pHDim,
									const Vec2& oPos, const Vec2& oHDim);

	bool isPlayerDead(const std::string& type, CBoundingBox& pbox, CTransform& ptrans);
	bool outside(const Vec2& pos, const Vec2& dim);
};
