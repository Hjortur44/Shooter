#pragma once

#include "Scene.h"
#include "../Managers/MapManager.h"
#include "../Math/Vec2.h"
#include "../Systems/Movements/EnemyMovement.h"
#include "../Systems/Movements/PlayerMovement.h"
#include "../Systems/Spawner.h"

class ScenePlay : public Scene
{
public:
  ScenePlay();
  ~ScenePlay();

	void mapNumber(const int number);
  void update() override;

private:
	EnemyMovement  m_enemyMovement;
	PlayerMovement m_playerMovement;

	Spawner m_spawner;
};