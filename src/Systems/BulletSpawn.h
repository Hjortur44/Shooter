#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "Controls.h"

class BulletSpawn
{
		Controls             m_cont;
		ComponentMemoryPool& m_componentPool = ComponentMemoryPool::Instance();

	public:
		BulletSpawn();
		~BulletSpawn();

		void shoot();
};