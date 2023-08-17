#include "Components.h"

CMovement::CMovement() {}
CMovement::CMovement(bool activate) : isActive(activate) {}

const Vec2& CMovement::diagonal() const
{
	return m_diagonal;
}


const Vec2& CMovement::down() const
{
	return m_down;
}


const Vec2& CMovement::left() const
{
	return m_left;
}


const Vec2& CMovement::right() const
{
	return m_right;
}


const Vec2& CMovement::up() const
{
	return m_up;
}