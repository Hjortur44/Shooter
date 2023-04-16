#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <iostream>

class EntityManager
{
  EntityManager();

  void createBullet();
  void createEnemy();
  void createPlayer();

  void destroyBullet();
  void destroyEnemy();
  void destroyPlayer();

  ComponentMemoryPool& m_componentPool = ComponentMemoryPool::Instance();

  std::vector<size_t> m_bulletsToEnable;
  std::vector<size_t> m_enemiesToEnable;
  std::vector<size_t> m_playersToEnable;

  std::vector<size_t> m_bulletsToDisable;
  std::vector<size_t> m_enemiesToDisable;
  std::vector<size_t> m_playersToDisable;

  std::vector<size_t> m_bulletConfigMap;
  std::vector<size_t> m_enemyConfigMap;
  std::vector<size_t> m_playerConfigMap;

  sf::Texture m_texture;

public:
  EntityManager(EntityManager&) = delete;

  static EntityManager& Instance();

  const std::vector<Entity>& getEntities();

  void addBullet();
  void addEnemy();
  void addPlayer();

  void removeBullet(const size_t id);
  void removeEnemy(const size_t id);
  void removePlayer(const size_t id);

  void update();
};
