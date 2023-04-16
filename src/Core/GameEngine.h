#pragma once

#include "../Managers/AssetManager.h"
#include "../Managers/EntityManager.h"
#include "../MemoryPools/ComponentMemoryPool.h"
#include "../Scenes/Scene.h"
#include "../Scenes/Scene_Play.h"
#include "../Scenes/Scene_Menu.h"
#include "../Systems/Action.h"
#include "../Systems/Movement.h"
#include "../Systems/Input.h"
#include "../Systems/BulletSpawn.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <iostream>

class GameEngine
{
  sf::RenderWindow m_window;

  ComponentMemoryPool& m_compMemPool   = ComponentMemoryPool::Instance();
  EntityManager&       m_entityManager = EntityManager::Instance();
  Input&               m_input         = Input::Instance();

  Movement    m_movement;
  BulletSpawn m_bulletSpawn;

  std::string m_currentScene = "";

  bool   m_paused          = false;
  size_t m_simulationSpeed = 1;
  size_t m_windowWidth     = 0;
  size_t m_windowHeight    = 0;
  size_t m_frameLimit      = 0;

  void init();
  void sUserInput();
  void sRender();
  void setPause(bool paused);
  void sMovement();
  void sLifespan();
  void sEnemySpawner();
  void sBulletSpawner();
  void sCollision();

public:
  GameEngine();

  sf::RenderWindow& window();

  void run();
  void update();
  void quit();
};
