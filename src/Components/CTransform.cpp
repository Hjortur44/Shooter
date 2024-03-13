#include "CTransform.hpp"

CTransform::CTransform() {}

CTransform::CTransform(const Vec2& position, const Vec2& velocity, bool activate)
 : currentPosition(position), previousPosition(position), velocity(velocity), isActive(activate) {}

const bool CTransform::alive()
{
	return m_alive;
}


void CTransform::active(const bool activate)
{
	m_alive = activate;
}