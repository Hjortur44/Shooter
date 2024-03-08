#pragma once

#include "../Systems/Input.hpp"
#include "../Systems/Physics.hpp"
#include "../Systems/Renderer.hpp"

class GameEngine
{
public:
  GameEngine();
  ~GameEngine();

  void run();

private:
	Physics  m_physics;
  Renderer m_renderer;
};