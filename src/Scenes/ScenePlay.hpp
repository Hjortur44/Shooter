#pragma once

#include "Scene.hpp"
#include "../Systems/Movements/EnemyMovement.hpp"
#include "../Systems/Movements/PlayerMovement.hpp"
#include "../Systems/Spawner.hpp"

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