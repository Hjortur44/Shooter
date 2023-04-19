#include "Movement.h"

#include <iostream>

Movement::Movement()
{
	normal = normal.normalize(Vec2(0, 0), Vec2(1, 1));
}

Movement::~Movement() {}

void Movement::moving()
{
	momentum = {0, 0};

  // Straight up
  if(m_cont.isRequestingUp())
  {
    momentum = u;
  }

  // Straight down
  if(m_cont.isRequestingDown())
  {
    momentum = d;
  }

  // Straight left
  if(m_cont.isRequestingLeft())
  {
    momentum = l;
  }

  // Straight right
  if(m_cont.isRequestingRight())
  {
    momentum = r;
  }

  // Diagonal up and left
  if(m_cont.isRequestingUp() && m_cont.isRequestingLeft())
  {
		momentum.x = -normal.x;
		momentum.y = -normal.y;
  }

  // Diagonal up and right
  if(m_cont.isRequestingUp() && m_cont.isRequestingRight())
  {
		momentum.x = normal.x;
		momentum.y = -normal.y;
  }

  // Diagonal down and left
  if(m_cont.isRequestingDown() && m_cont.isRequestingLeft())
  {
		momentum.x = -normal.x;
		momentum.y = normal.y;
  }

  // Diagonal down and right
  if(m_cont.isRequestingDown() && m_cont.isRequestingRight())
  {
		momentum.x = normal.x;
		momentum.y = normal.y;
  }

  shape.circle.setPosition
  (
    shape.circle.getPosition().x + momentum.x,
    shape.circle.getPosition().y + momentum.y
  );
}
