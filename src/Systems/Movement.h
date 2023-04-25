#pragma once

#include "Controls.h"
#include "../Entities/Entity.h"
#include "../Managers/EntityManager.h"
#include "../Math/Vec2.h"

#include <iostream>

class Movement
{
public:
  Movement();
  ~Movement();

	void playerMovement();
  void update();

private:
	Controls m_cont;

	Vec2 m_norm = {0, 0};
  Vec2 m_d    = {0, 1};
  Vec2 m_l    = {-1, 0};
  Vec2 m_r    = {1, 0};
  Vec2 m_u    = {0, -1};
};
