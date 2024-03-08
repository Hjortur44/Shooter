#pragma once

#include "Spawner.hpp"

class EntitySpawner : public Spawner
{
public:
  EntitySpawner();
  ~EntitySpawner();

	void spawnBullet(const int x, const int y);
	void spawnEnemy();
	void spawnPlayer();
	void update(const int number) override;
};