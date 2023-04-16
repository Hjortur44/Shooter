#pragma once

#include "../Managers/EntityManager.h"
#include "Controls.h"

class BulletSpawn
{
  Controls       m_cont;
  EntityManager& m_entityManager = EntityManager::Instance();

public:
  BulletSpawn();
  ~BulletSpawn();

  void shoot();
};
