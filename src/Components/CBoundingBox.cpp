#include "CBoundingBox.hpp"

CBoundingBox::CBoundingBox() {}

CBoundingBox::CBoundingBox(bool activate)	: isActive(activate) {}

const bool CBoundingBox::alive()
{
	return m_alive;
}


void CBoundingBox::active(const bool activate)
{
	m_alive = activate;
}