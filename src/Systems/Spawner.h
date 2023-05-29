#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Managers/ComponentManager.h"
#include "../Math/Vec2.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Spawner
{
public:
  Spawner(const int baseSize);
  ~Spawner();

	void spawnBullet(const int x, const int y);
	void spawnEnemy();
	void spawnPlayer();

	void spawn();

private:
	int m_baseSize = 0;
};
