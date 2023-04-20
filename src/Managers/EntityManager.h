#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

class EntityManager
{
public:
  EntityManager(EntityManager&) = delete;

  static EntityManager& Instance();

  const std::vector<Entity>& getEntities();

  void addBullet();
  void addEnemy();
  void addPlayer();

  void removeBullet(const int id);
  void removeEnemy(const int id);
  void removePlayer(const int id);

  void update();

private:
  EntityManager();

  void createBullet();
  void createEnemy();
  void createPlayer();

  void destroyBullet();
  void destroyEnemy();
  void destroyPlayer();

  std::vector<int> m_bulletsToEnable;
  std::vector<int> m_enemiesToEnable;
  std::vector<int> m_playersToEnable;

  std::vector<int> m_bulletsToDisable;
  std::vector<int> m_enemiesToDisable;
  std::vector<int> m_playersToDisable;

  std::vector<int> m_bulletConfigMap;
  std::vector<int> m_enemyConfigMap;
  std::vector<int> m_playerConfigMap;

  sf::Texture m_texture;
};
