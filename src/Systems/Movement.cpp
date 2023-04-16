#include "Movement.h"

Movement::Movement() {}

Movement::~Movement() {}

void Movement::moving()
{
  trans.velocity = s;

  // Straight up
  if(m_cont.isRequestingUp())
  {
    trans.velocity += u;
  }

  // Straight down
  if(m_cont.isRequestingDown())
  {
    trans.velocity += d;
  }

  // Straight left
  if(m_cont.isRequestingLeft())
  {
    trans.velocity += l;
  }

  // Straight right
  if(m_cont.isRequestingRight())
  {
    trans.velocity += r;
  }

  // Diagonal up and left
  if(m_cont.isRequestingUp() && m_cont.isRequestingLeft())
  {
    trans.velocity += ul;
  }

  // Diagonal up and right
  if(m_cont.isRequestingUp() && m_cont.isRequestingRight())
  {
    trans.velocity += ur;
  }

  // Diagonal down and left
  if(m_cont.isRequestingDown() && m_cont.isRequestingLeft())
  {
    trans.velocity += dl;
  }

  // Diagonal down and right
  if(m_cont.isRequestingDown() && m_cont.isRequestingRight())
  {
    trans.velocity += dr;
  }

  shape.circle.setPosition
  (
    shape.circle.getPosition().x + trans.velocity.x,
    shape.circle.getPosition().y + trans.velocity.y
  );
}
