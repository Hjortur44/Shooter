#pragma once

#include "../Entities/Entity.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Math/Vec2.h"
#include "../Systems/Input.h"

#include <vector>

class Movement
{
public:
  Movement();
  ~Movement();

  void keyPressed(int key);
  void keyReleased(int key);
  void update();

private:
	Vec2 playerMovement();
	Vec2 oneKey(Input& input);
	Vec2 twoKeys(Input& input);
	Vec2 threeKeys(Input& input);

  Vec2 m_diagonal = {0.707106781f, 0.707106781f};
  Vec2 m_down     = {0.0f, 1.0f};
  Vec2 m_left     = {-1.0f, 0.0f};
  Vec2 m_right    = {1.0f, 0.0f};
  Vec2 m_up       = {0.0f, -1.0f};
};
