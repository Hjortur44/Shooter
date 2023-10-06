#pragma once

#include "../Math/Vec2.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Systems/Input.h"
#include "../Systems/Physics.h"
#include "../Systems/Renderer.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class GameEngine
{
public:
  GameEngine();
  ~GameEngine();

  void run();

private:
  void init();

	Vec2 m_winDim = {640.0f, 480.0f};

	Physics        m_physics;
  Renderer       m_renderer = m_winDim;

	int m_bs = 32;
};