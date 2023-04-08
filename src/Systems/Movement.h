#pragma once

#include "../Components/ComponentMemoryPool.h"
#include "../Math/Vec2.h"
#include "Controls.h"

class Movement
{
	ComponentMemoryPool& m_pool = ComponentMemoryPool::Instance();
	CShape&              m_s    = m_pool.getComponent<CShape>(0); // this should be the player shape
	CTransform&          m_t    = m_pool.getComponent<CTransform>(0); // this should be the player transform

	Controls						 m_cont;

	Vec2 m_normUpLeft    = {0, 0};
	Vec2 m_normUpRight   = {0, 0};
	Vec2 m_normDownLeft  = {0, 0};
	Vec2 m_normDownRight = {0, 0};

	public:
		Movement();
		~Movement();

		void moving();
};