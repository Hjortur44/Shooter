#pragma once

#include "Spawner.h"
#include "Controls.h"

class BulletSpawn
{
		Controls m_cont;
		Spawner  m_spawn;

	public:
		BulletSpawn();
		~BulletSpawn();

		void shoot();
};