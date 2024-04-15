#include "CDirection.hpp"

CDirection::CDirection() {}
CDirection::~CDirection() {}

const bool CDirection::active()
{
	return m_alive;
}


void CDirection::activate(const bool activate)
{
	m_alive = activate;
}