#include "CLifespan.hpp"

CLifespan::CLifespan() {}
CLifespan::~CLifespan() {}

const bool CLifespan::active()
{
	return m_alive;
}


void CLifespan::activate(const bool activate)
{
	m_alive = activate;
}