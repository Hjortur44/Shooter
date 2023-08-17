#pragma once

#include "../Grid/Grid.h"
#include "../Math/Vec2.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Systems/Controller.h"
#include "../Systems/Movement.h"
#include "../Systems/Physics.h"
#include "../Systems/Renderer.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class GameEngine
{
public:
  GameEngine();

  void quit();
  void run();
  void update();

private:
  void init();

	void sPhysics();
	void sRender();
  void sUserInput();

	Vec2 m_winDim = {640.0f, 480.0f};

	int m_bs = 32;

	Controller m_controller;
	Grid 		   m_grid        = {m_winDim, m_bs};
	Movement   m_movement;
	Physics    m_physics;
  Renderer   m_renderer    = m_winDim;
};