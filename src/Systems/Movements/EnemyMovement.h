#pragma once

#include "Movement.h"
#include "../../Entities/Entity.h"
#include "../../Managers/EntityComponentsManager.h"
#include "../../Math/Vec2.h"

#include <vector>

class EnemyMovement : public Movement
{
public:
  EnemyMovement();
  ~EnemyMovement();

  void update();
};
