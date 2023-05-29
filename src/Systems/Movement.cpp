#include "Movement.h"

Movement::Movement() {}

Movement::~Movement() {}

void Movement::update()
{
	Entity player = ComponentManager::Instance().player();
	CController& cont = player.getComponent<CController>();
	cont.direction = playerMovement(cont);
}


// private
Vec2 Movement::playerMovement(CController& cont)
{
	Vec2 dir(0.0f, 0.0f);

	switch(cont.keyCount)
	{
		case 1:
			dir = oneKey(cont);
		break;
		case 2:
			dir = twoKeys(cont);
		break;
		case 3:
			dir = threeKeys(cont);
		break;
	}

	return dir;
}


Vec2 Movement::oneKey(CController& cont)
{
	Vec2 dir(0.0f, 0.0f);

	if(cont.down)
  {
    dir += m_d;
  }

	if(cont.left)
  {
    dir += m_l;
  }

	if(cont.right)
  {
    dir += m_r;
  }

  if(cont.up)
  {
    dir += m_u;
  }

	return dir;
}


Vec2 Movement::twoKeys(CController& cont)
{
	Vec2 dir(0.0f, 0.0f);

  if(cont.down && cont.left)
  {
    dir.x = -m_dig.x;
		dir.y = m_dig.y;
  }

  if(cont.down && cont.right)
  {
    dir.x = m_dig.x;
		dir.y = m_dig.y;
  }

  if(cont.up && cont.left)
  {
    dir.x = -m_dig.x;
		dir.y = -m_dig.y;
  }

  if(cont.up && cont.right)
  {
    dir.x = m_dig.x;
		dir.y = -m_dig.y;
  }

	return dir;
}


Vec2 Movement::threeKeys(CController& cont)
{
	Vec2 dir(0.0f, 0.0f);

  if(cont.up && cont.left && cont.right)
  {
    dir = m_u;
  }

  if(cont.down && cont.left && cont.right)
  {
    dir = m_d;
  }

  if(cont.left && cont.down && cont.up)
  {
    dir = m_l;
  }

  if(cont.right && cont.down&& cont.up)
  {
    dir = m_r;
  }

	return dir;
}