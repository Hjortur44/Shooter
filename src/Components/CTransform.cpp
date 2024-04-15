#include "CTransform.hpp"

CTransform::CTransform() {}

CTransform::~CTransform() {}

const bool CTransform::active()
{
	return m_alive;
}


void CTransform::activate(const bool activate)
{
	m_alive = activate;
}