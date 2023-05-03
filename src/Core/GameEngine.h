#pragma once

#include "../Managers/EntityManager.h"
#include "../Systems/Input.h"
#include "../Systems/Physics.h"
#include "../Systems/Spawner.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class GameEngine
{
public:
  GameEngine();

  sf::RenderWindow& window();

  void quit();
  void run();
  void update();

private:
  void init();

	void sRender();
  void sUserInput();

  sf::RenderWindow m_window;

	Physics m_physics;
};
