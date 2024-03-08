#include "PlayerMovement.hpp"

PlayerMovement::PlayerMovement() {}

PlayerMovement::~PlayerMovement() {}

void PlayerMovement::update() {}

// private
Vec2 PlayerMovement::movement()
{
	Input& input = Input::Instance();

	Vec2 directions = {0.0f, 0.0f};

	switch(input.keyCount())
	{
		case 1:
			directions = oneKey(input);
		break;
		case 2:
			directions = twoKeys(input);
		break;
		case 3:
			directions = threeKeys(input);
		break;
	}

	return directions;
}


Vec2 PlayerMovement::oneKey(Input& input)
{
	Vec2 directions = {0.0f, 0.0f};

	// TODO: check if switch can be used (with ints).
	if(input.isKey(18))
  {
    directions += m_down;
  }

	if(input.isKey(0))
  {
    directions += m_left;
  }

	if(input.isKey(3))
  {
   directions += m_right;
  }

  if(input.isKey(22))
  {
    directions += m_up;
  }

	return directions;
}


Vec2 PlayerMovement::twoKeys(Input& input)
{
	Vec2 directions = {0.0f, 0.0f};

  if(input.isKey(18) && input.isKey(0))
  {
    directions.x = -m_diagonal.x;
		directions.y = m_diagonal.y;
  }

  if(input.isKey(18) && input.isKey(3))
  {
    directions.x = m_diagonal.x;
		directions.y = m_diagonal.y;
  }

  if(input.isKey(22) && input.isKey(0))
  {
    directions.x = -m_diagonal.x;
		directions.y = -m_diagonal.y;
  }

  if(input.isKey(22) && input.isKey(3))
  {
    directions.x = m_diagonal.x;
		directions.y = -m_diagonal.y;
  }

	return directions;
}


Vec2 PlayerMovement::threeKeys(Input& input)
{
	Vec2 directions = {0.0f, 0.0f};

  if(input.isKey(22) && input.isKey(0) && input.isKey(3))
  {
    directions = m_up;
  }

  if(input.isKey(18) && input.isKey(0) && input.isKey(3))
  {
    directions = m_down;
  }

  if(input.isKey(0) && input.isKey(18) && input.isKey(22))
  {
    directions = m_left;
  }

  if(input.isKey(3) && input.isKey(18)&& input.isKey(22))
  {
    directions = m_right;
  }

	return directions;
}