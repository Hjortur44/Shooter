#pragma once

#include "Controls.h"
#include "../Managers/EntityManager.h"

class BulletSpawn
{
public:
  BulletSpawn();
  ~BulletSpawn();

  void shoot();

private:
  Controls m_cont;
};
