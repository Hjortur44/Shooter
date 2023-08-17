#pragma once

#include "../Entities/Entity.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Math/Vec2.h"

#include <vector>

class Movement
{
public:
  Movement();
  ~Movement();

  void update();

private:
	void playerMovement(CController& cont, CMovement& move);
	void oneKey(CController& cont, CMovement& move);
	void twoKeys(CController& cont, CMovement& move);
	void threeKeys(CController& cont, CMovement& move);
};
