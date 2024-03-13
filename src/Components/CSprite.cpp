#include "CSprite.hpp"

CSprite::CSprite() {}

CSprite::CSprite(bool activate) : isActive(activate) {}

const bool CSprite::alive()
{
	return m_alive;
}


void CSprite::active(const bool activate)
{
	m_alive = activate;
}