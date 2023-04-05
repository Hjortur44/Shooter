#include "Movement.h"

Movement::Movement()
{
	m_normUpLeft.normalize(m_t.velocityUp, m_t.velocityLeft);
	m_normUpRight.normalize(m_t.velocityUp, m_t.velocityRight);
	m_normDownLeft.normalize(m_t.velocityDown, m_t.velocityLeft);
	m_normDownRight.normalize(m_t.velocityDown, m_t.velocityRight);
}

Movement::~Movement() {}

void Movement::moving()
{
	// Straight up
	if(m_cont.isRequestingUp())
	{
		m_t.currentPosition += m_t.velocityUp;
	}

	// Straight down
	if(m_cont.isRequestingDown())
	{
		m_t.currentPosition += m_t.velocityDown;
	}

	// Straight left
	if(m_cont.isRequestingLeft())
	{
		m_t.currentPosition += m_t.velocityLeft;
	}

	// Straight right
	if(m_cont.isRequestingRight())
	{
		m_t.currentPosition += m_t.velocityRight;
	}

	// Diagonal up and left
	if(m_cont.isRequestingUp() && m_cont.isRequestingLeft())
	{
		m_t.currentPosition += m_normUpLeft;
	}

	// Diagonal up and right
	if(m_cont.isRequestingUp() && m_cont.isRequestingRight())
	{
		m_t.currentPosition += m_normUpRight;
	}

	// Diagonal down and left
	if(m_cont.isRequestingDown() && m_cont.isRequestingLeft())
	{
		m_t.currentPosition += m_normDownLeft;
	}

	// Diagonal down and right
	if(m_cont.isRequestingDown() && m_cont.isRequestingRight())
	{
		m_t.currentPosition += m_normDownRight;
	}

	m_s.position = m_t.currentPosition;
}