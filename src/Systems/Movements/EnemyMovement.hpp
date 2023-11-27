#pragma once

#include "Movement.hpp"

class EnemyMovement : public Movement
{
public:
  EnemyMovement();
  ~EnemyMovement();

  void update();
};
