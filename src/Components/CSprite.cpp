#include "CSprite.hpp"

CSprite::CSprite() {}
CSprite::~CSprite() {}

const bool CSprite::active()
{
	return m_alive;
}


void CSprite::activate(const bool activate)
{
	m_alive = activate;
}