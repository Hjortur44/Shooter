#include "CLifespan.hpp"

CLifespan::CLifespan() {}

CLifespan::CLifespan(int total, bool activate) : isActive(activate), remaining(total), total(total) {}


const bool CLifespan::alive()
{
	return m_alive;
}


void CLifespan::active(const bool activate)
{
	m_alive = activate;
}