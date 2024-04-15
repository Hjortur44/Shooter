#include "CBoundingBox.hpp"

CBoundingBox::CBoundingBox() {}

CBoundingBox::~CBoundingBox() {}

const bool CBoundingBox::active()
{
	return m_alive;
}


void CBoundingBox::activate(const bool activate)
{
	m_alive = activate;
}