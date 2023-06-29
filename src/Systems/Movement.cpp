#include "Movement.h"

Movement::Movement() {}

Movement::~Movement() {}

void Movement::update()
{
	Entity player = ComponentManager::Instance().player();

	CCollision&  coll  = player.getComponent<CCollision>();
	CController& cont  = player.getComponent<CController>();
	CTransform&  trans = player.getComponent<CTransform>();

	trans.previousPosition = trans.currentPosition;
	trans.currentPosition += (trans.velocity * cont.directionLR);
	trans.currentPosition += (trans.velocity * cont.directionUD);

	playerMovement(coll, cont);
}


// private
void Movement::playerMovement(CCollision& coll, CController& cont)
{
	cont.directionLR = {0.0f, 0.0f};
	cont.directionUD = {0.0f, 0.0f};

	switch(cont.keyCount)
	{
		case 1:
			oneKey(coll, cont);
		break;
		case 2:
			twoKeys(coll, cont);
		break;
		case 3:
			threeKeys(coll, cont);
		break;
	}
}


void Movement::oneKey(CCollision& coll, CController& cont)
{
	cont.directionLR = {0.0f, 0.0f};
	cont.directionUD = {0.0f, 0.0f};

	if(!coll.collisionD && cont.down)
  {
    cont.directionUD += m_d;
  }

	if(!coll.collisionL && cont.left)
  {
    cont.directionLR += m_l;
  }

	if(!coll.collisionR && cont.right)
  {
   cont.directionLR += m_r;
  }

  if(!coll.collisionU && cont.up)
  {
    cont.directionUD += m_u;
  }
}


void Movement::twoKeys(CCollision& coll, CController& cont)
{
	cont.directionLR = {0.0f, 0.0f};
	cont.directionUD = {0.0f, 0.0f};

  if(!coll.collisionD && !coll.collisionL && cont.down && cont.left)
  {
    cont.directionLR.x = -m_dig.x;
		cont.directionUD.y = m_dig.y;
  }

  if(!coll.collisionD && !coll.collisionR && cont.down && cont.right)
  {
    cont.directionLR.x = m_dig.x;
		cont.directionUD.y = m_dig.y;
  }

  if(!coll.collisionU && !coll.collisionL && cont.up && cont.left)
  {
    cont.directionLR.x = -m_dig.x;
		cont.directionUD.y = -m_dig.y;
  }

  if(!coll.collisionU && !coll.collisionR && cont.up && cont.right)
  {
    cont.directionLR.x = m_dig.x;
		cont.directionUD.y = -m_dig.y;
  }
}


void Movement::threeKeys(CCollision& coll, CController& cont)
{
	cont.directionLR = {0.0f, 0.0f};
	cont.directionUD = {0.0f, 0.0f};

  if(cont.up && cont.left && cont.right)
  {
    cont.directionUD = m_u;
  }

  if(cont.down && cont.left && cont.right)
  {
    cont.directionUD = m_d;
  }

  if(cont.left && cont.down && cont.up)
  {
    cont.directionLR = m_l;
  }

  if(cont.right && cont.down&& cont.up)
  {
    cont.directionLR = m_r;
  }
}