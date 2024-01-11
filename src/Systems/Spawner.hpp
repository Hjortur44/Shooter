#pragma once

#include "../Entities/Entity.hpp"
#include "../Managers/AssetManager.hpp"
#include "../Managers/ConfigurationManager.hpp"
#include "../Managers/EntityManager.hpp"
#include "../Math/Vec2.hpp"

#include <iostream>
#include <string>
#include <vector>

class Spawner
{
public:
  Spawner();
  ~Spawner();

	void spawnBullet(const int x, const int y);
	void spawnEnemy();
	void spawnPlayer();
	void update(const int number);
};