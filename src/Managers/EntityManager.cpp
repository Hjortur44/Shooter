#include "EntityManager.h"

EntityManager& EntityManager::Instance()
{
  static EntityManager INSTANCE;
  return INSTANCE;
}


void EntityManager::addBullet()
{
  m_bulletsToEnable.push_back(ComponentMemoryPool::Instance().addEntity());
}


void EntityManager::addEnemy()
{
  m_enemiesToEnable.push_back(ComponentMemoryPool::Instance().addEntity());
}


void EntityManager::addPlayer()
{
  m_playersToEnable.push_back(ComponentMemoryPool::Instance().addEntity());
}


void EntityManager::removeBullet(const int id)
{
  m_bulletsToDisable.push_back(id);
}


void EntityManager::removeEnemy(const int id)
{
  m_enemiesToDisable.push_back(id);
}


void EntityManager::removePlayer(const int id)
{
  m_playersToDisable.push_back(id);
}


void EntityManager::update()
{
  if(!m_bulletsToEnable.empty())
  {
    createBullet();

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

  m_texture = AssetManager::Instance().getAsset("wood");
}


void EntityManager::createBullet()
{
  for(int id : m_bulletsToEnable)
  {
    ComponentMemoryPool::Instance().modifyComponent<CShape>
    (
      id,
      Vec2(m_bulletConfigMap.at(0), m_bulletConfigMap.at(1)),
      Vec2(m_bulletConfigMap.at(2), m_bulletConfigMap.at(3)),
      m_texture,
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CTransform>
    (
      id,
      Vec2(m_bulletConfigMap.at(4), m_bulletConfigMap.at(4)),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CLifespan>
    (
      id,
      m_bulletConfigMap.at(5),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CBoundingBox>
    (
      id,
      Vec2(m_bulletConfigMap.at(0),	m_bulletConfigMap.at(0)),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CCollision>
    (
      id,
			true
    );
  }

  m_bulletsToEnable.clear();
}


void EntityManager::createEnemy()
{
  for(int id : m_enemiesToEnable)
  {
    ComponentMemoryPool::Instance().modifyComponent<CShape>
    (
      id,
      Vec2(m_enemyConfigMap.at(0), m_enemyConfigMap.at(1)),
      Vec2(m_enemyConfigMap.at(2), m_enemyConfigMap.at(3)),
      m_texture,
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CTransform>
    (
      id,
      Vec2(m_enemyConfigMap.at(4), m_enemyConfigMap.at(4)),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CLifespan>
    (
      id,
      m_enemyConfigMap.at(5),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CCollision>
    (
      id,
			true
    );
  }
}


void EntityManager::createPlayer()
{
  for(int id : m_playersToEnable)
  {
    ComponentMemoryPool::Instance().modifyComponent<CShape>
    (
      id,
      Vec2(m_playerConfigMap.at(0), m_playerConfigMap.at(1)),
      Vec2(m_playerConfigMap.at(2), m_playerConfigMap.at(3)),
      m_texture,
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CTransform>
    (
      id,
      Vec2(m_playerConfigMap.at(4), m_playerConfigMap.at(4)),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CLifespan>
    (
      id,
      m_playerConfigMap.at(5),
			true
    );

    ComponentMemoryPool::Instance().modifyComponent<CCollision>
    (
      id,
			true
    );
  }
}


void EntityManager::destroyBullet()
{
  for(int id : m_bulletsToDisable)
  {
    ComponentMemoryPool::Instance().removeEntity(id);
  }
}

void EntityManager::destroyEnemy()
{
  for(int id : m_enemiesToDisable)
  {
    ComponentMemoryPool::Instance().removeEntity(id);
  }
}

void EntityManager::destroyPlayer()
{
  for(int id : m_playersToDisable)
  {
    ComponentMemoryPool::Instance().removeEntity(id);
  }
}
