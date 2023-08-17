#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <string>

class Spawner
{
public:
  Spawner();
  ~Spawner();

	void spawnBullet(const int x, const int y);
	void spawnEnemy();
	void spawnPlayer();
};