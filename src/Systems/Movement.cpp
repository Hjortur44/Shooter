#include "Movement.h"

Movement::Movement()
{
}

Movement::~Movement() {}

void Movement::moving()
{
  // Straight up
  if(m_cont.isRequestingUp())
  {
  }

  // Straight down
  if(m_cont.isRequestingDown())
  {
  }

  // Straight left
  if(m_cont.isRequestingLeft())
  {
  }

  // Straight right
  if(m_cont.isRequestingRight())
  {
  }

  // Diagonal up and left
  if(m_cont.isRequestingUp() && m_cont.isRequestingLeft())
  {
  }

  // Diagonal up and right
  if(m_cont.isRequestingUp() && m_cont.isRequestingRight())
  {
  }

  // Diagonal down and left
  if(m_cont.isRequestingDown() && m_cont.isRequestingLeft())
  {
  }

  // Diagonal down and right
  if(m_cont.isRequestingDown() && m_cont.isRequestingRight())
  {
  }
}
