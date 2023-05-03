#include "Movement.h"

Movement::Movement() {}

Movement::~Movement() {}

Vec2 Movement::playerMovement()
{
	Input& input = Input::Instance();
	Vec2 vel(0.0f, 0.0f);

	switch(input.keyCount())
	{
		case 1:
			vel = oneKey(input);
		break;
		case 2:
			vel = twoKeys(input);
		break;
		case 3:
			vel = threeKeys(input);
		break;
		default:
			input.keyCountReset();
	}

	return vel;
}


// private
Vec2 Movement::oneKey(Input& input)
{
	Vec2 vel(0.0f, 0.0f);

	if(input.isKey(18))
  {
    vel += m_d;
  }

	if(input.isKey(0))
  {
    vel += m_l;
  }

	if(input.isKey(3))
  {
    vel += m_r;
  }

  if(input.isKey(22))
  {
    vel += m_u;
  }

	return vel;
}


Vec2 Movement::twoKeys(Input& input)
{
	Vec2 vel(0.0f, 0.0f);

  if(input.isKey(18) && input.isKey(0))
  {
    vel.x = -m_dig.x;
		vel.y = m_dig.y;
  }

  if(input.isKey(18) && input.isKey(3))
  {
    vel.x = m_dig.x;
		vel.y = m_dig.y;;
  }

  if(input.isKey(22) && input.isKey(0))
  {
    vel.x = -m_dig.x;
		vel.y = -m_dig.y;
  }

  if(input.isKey(22) && input.isKey(3))
  {
    vel.x = m_dig.x;
		vel.y = -m_dig.y;
  }

	return vel;
}


Vec2 Movement::threeKeys(Input& input)
{
	Vec2 vel(0.0f, 0.0f);

  if(input.isKey(22) && input.isKey(0) && input.isKey(3))
  {
    vel = m_u;
  }

  if(input.isKey(18) && input.isKey(0) && input.isKey(3))
  {
    vel = m_d;
  }

  if(input.isKey(0) && input.isKey(18) && input.isKey(22))
  {
    vel = m_l;
  }

  if(input.isKey(3) && input.isKey(18) && input.isKey(22))
  {
    vel = m_r;
  }

	return vel;
}