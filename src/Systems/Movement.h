#pragma once

#include "Input.h"
#include "../Math/Vec2.h"

#include <cstddef>

class Movement
{
public:
  Movement();
  ~Movement();

	Vec2 playerMovement();

  void update();

private:
	Vec2 oneKey(Input& input);
	Vec2 twoKeys(Input& input);
	Vec2 threeKeys(Input& input);

  Vec2 m_dig = {0.707106781f, 0.707106781f};

  Vec2 m_d = {0.0f, 1.0f};
  Vec2 m_l = {-1.0f, 0.0f};
  Vec2 m_r = {1.0f, 0.0f};
  Vec2 m_u = {0.0f, -1.0f};
};
