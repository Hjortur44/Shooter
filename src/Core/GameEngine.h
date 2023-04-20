#pragma once

#include "../Managers/AssetManager.h"
#include "../Managers/EntityManager.h"
#include "../MemoryPools/ComponentMemoryPool.h"
#include "../Systems/Action.h"
#include "../Systems/BulletSpawn.h"
#include "../Systems/Movement.h"
#include "../Systems/Input.h"
#include "../Systems/Physics.h"
#include "../Scenes/Scene.h"
#include "../Scenes/Scene_Play.h"
#include "../Scenes/Scene_Menu.h"

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>

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
  void setPause(bool paused);

  void sBulletSpawner();
  void sCollision();
  void sEnemySpawner();
  void sMovement();
  void sLifespan();
	void sRender();
  void sUserInput();

  sf::RenderWindow m_window;

  BulletSpawn m_bulletSpawn;
  Movement    m_movement;
	Physics     m_physics;

  std::string m_currentScene = "";

  bool m_paused = false;

  int m_frameLimit      = 0;
  int m_simulationSpeed = 1;
  int m_windowHeight    = 0;
  int m_windowWidth     = 0;
};
