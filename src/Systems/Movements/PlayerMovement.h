#pragma once

#include "Movement.h"
#include "../../Entities/Entity.h"
#include "../../Managers/EntityComponentsManager.h"
#include "../../Math/Vec2.h"
#include "../Input.h"

#include <iostream>
#include <vector>

class PlayerMovement : public Movement
{
public:
  PlayerMovement();
	~PlayerMovement();

  void update();

private:
	Vec2 movement();
	Vec2 oneKey(Input& input);
	Vec2 twoKeys(Input& input);
	Vec2 threeKeys(Input& input);
};
