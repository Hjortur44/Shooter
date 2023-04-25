#include "Movement.h"

Movement::Movement()
{
	m_norm = m_norm.normalize(Vec2(0, 0), Vec2(1, 1));
}

Movement::~Movement() {}

void Movement::playerMovement()
{
	Entity e = EntityManager::Instance().entity(0);
	CTransform& t = e.getComponent<CTransform>();

	Vec2 m = Vec2(0, 0);

  // Straight up
  if(m_cont.isRequestingUp())
  {
    m += m_u * t.velocity;
  }

  // Straight down
  if(m_cont.isRequestingDown())
  {
    m += m_d * t.velocity;
  }

  // Straight left
  if(m_cont.isRequestingLeft())
  {
    m += m_l * t.velocity;
  }

  // Straight right
  if(m_cont.isRequestingRight())
  {
    m += m_r * t.velocity;
  }

  // Diagonal up and left
  if(m_cont.isRequestingUp() && m_cont.isRequestingLeft())
  {
		m += Vec2(-m_norm.x, -m_norm.y) * t.velocity;
  }

  // Diagonal up and right
  if(m_cont.isRequestingUp() && m_cont.isRequestingRight())
  {
		m += Vec2(m_norm.x, -m_norm.y) * t.velocity;
  }

  // Diagonal down and left
  if(m_cont.isRequestingDown() && m_cont.isRequestingLeft())
  {
		m += Vec2(-m_norm.x, m_norm.y) * t.velocity;
  }

  // Diagonal down and right
  if(m_cont.isRequestingDown() && m_cont.isRequestingRight())
  {
		m += Vec2(m_norm.x, m_norm.y) * t.velocity;
  }

	t.position += m;
	e.getComponent<CShape>().position = t.position;
}