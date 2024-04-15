#pragma once

#include "../Input.hpp"
#include "../../Math/Vec2.hpp"

class PlayerMovement
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
