#pragma once

#include "Movement.hpp"
#include "../Input.hpp"

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
