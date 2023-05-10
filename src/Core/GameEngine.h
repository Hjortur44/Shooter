#pragma once

#include "../Grid/Grid.h"
#include "../Math/Vec2.h"
#include "../Managers/EntityManager.h"
#include "../Systems/Input.h"
#include "../Systems/Movement.h"
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

	sf::Font         m_font;
  sf::RenderWindow m_window;
	sf::Text         m_text;

	Grid     m_grid;
	Movement m_movement;
	Physics  m_physics;
	Spawner  m_spawner;
};
