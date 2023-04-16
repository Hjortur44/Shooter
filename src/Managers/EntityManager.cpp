#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


void EntityManager::addBullet()
{
  m_bulletsToEnable.push_back(m_componentPool.addEntity());
}


void EntityManager::addEnemy()
{
  m_enemiesToEnable.push_back(m_componentPool.addEntity());
}


void EntityManager::addPlayer()
{
  m_playersToEnable.push_back(m_componentPool.addEntity());
}


void EntityManager::removeBullet(const size_t id)
{
  m_bulletsToDisable.push_back(id);
}


void EntityManager::removeEnemy(const size_t id)
{
  m_enemiesToDisable.push_back(id);
}


void EntityManager::removePlayer(const size_t id)
{
  m_playersToDisable.push_back(id);
}


void EntityManager::update()
{
  if(!m_bulletsToEnable.empty())
  {
    createBullet();
    m_bulletsToEnable.clear();
  }

  if(!m_enemiesToEnable.empty())
  {
    createEnemy();
    m_enemiesToEnable.clear();
  }

  if(!m_playersToEnable.empty())
  {
    createPlayer();
    m_playersToEnable.clear();
  }


  if(!m_bulletsToDisable.empty())
  {
    destroyBullet();
    m_bulletsToDisable.clear();
  }

  if(!m_enemiesToDisable.empty())
  {
    destroyEnemy();
    m_enemiesToDisable.clear();
  }

  if(!m_playersToDisable.empty())
  {
    destroyPlayer();
    m_playersToDisable.clear();
  }
}


// private
EntityManager::EntityManager()
{
  ConfigurationManager& conf = ConfigurationManager::Instance();
  m_bulletConfigMap = conf.getConfigs("Bullet");
  m_enemyConfigMap = conf.getConfigs("Enemy");
  m_playerConfigMap = conf.getConfigs("Player");

  m_texture   = AssetManager::Instance().getAsset("wood");
}


void EntityManager::createBullet()
{
  for(size_t id : m_bulletsToEnable)
  {
    m_componentPool.modifyComponent<CShape>
    (
      id,
      Vec2(m_bulletConfigMap.at(0), m_bulletConfigMap.at(1)),
      Vec2(m_bulletConfigMap.at(2), m_bulletConfigMap.at(3)),
      m_texture
    );

    m_componentPool.modifyComponent<CTransform>
    (
      id,
      Vec2(m_bulletConfigMap.at(4), m_bulletConfigMap.at(4))
    );

    m_componentPool.modifyComponent<CLifespan>
    (
      id,
      m_bulletConfigMap.at(5)
    );
  }
}


void EntityManager::createEnemy()
{
  for(size_t id : m_enemiesToEnable)
  {
    m_componentPool.modifyComponent<CShape>
    (
      id,
      Vec2(m_enemyConfigMap.at(0), m_enemyConfigMap.at(1)),
      Vec2(m_enemyConfigMap.at(2), m_enemyConfigMap.at(3)),
      m_texture
    );

    m_componentPool.modifyComponent<CTransform>
    (
      id,
      Vec2(m_enemyConfigMap.at(4), m_enemyConfigMap.at(4))
    );

    m_componentPool.modifyComponent<CLifespan>
    (
      id,
      m_enemyConfigMap.at(5)
    );
  }
}


void EntityManager::createPlayer()
{
  for(size_t id : m_playersToEnable)
  {
    m_componentPool.modifyComponent<CShape>
    (
      id,
      Vec2(m_playerConfigMap.at(0), m_playerConfigMap.at(1)),
      Vec2(m_playerConfigMap.at(2), m_playerConfigMap.at(3)),
      m_texture
    );

    m_componentPool.modifyComponent<CTransform>
    (
      id,
      Vec2(m_playerConfigMap.at(4), m_playerConfigMap.at(4))
    );

    m_componentPool.modifyComponent<CLifespan>
    (
      id,
      m_playerConfigMap.at(5)
    );
  }
}


void EntityManager::destroyBullet()
{
  for(size_t id : m_bulletsToDisable)
  {
    m_componentPool.removeEntity(id);
  }
}

void EntityManager::destroyEnemy()
{
  for(size_t id : m_enemiesToDisable)
  {
    m_componentPool.removeEntity(id);
  }
}

void EntityManager::destroyPlayer()
{
  for(size_t id : m_playersToDisable)
  {
    m_componentPool.removeEntity(id);
  }
}
