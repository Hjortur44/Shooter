#pragma once

#include "../../Math/Vec2.hpp"

#include <iostream>

class Movement
{
public:
  virtual ~Movement();

	virtual void update() = 0;

protected:
  Vec2 m_diagonal = {0.707106781f, 0.707106781f};
  Vec2 m_down     = {0.0f, 1.0f};
  Vec2 m_left     = {-1.0f, 0.0f};
  Vec2 m_right    = {1.0f, 0.0f};
  Vec2 m_up       = {0.0f, -1.0f};
};
