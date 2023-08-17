#include "Movement.h"

Movement::Movement() {}

Movement::~Movement() {}

void Movement::update()
{
	std::vector<Entity> allPlayers = EntityComponentsManager::Instance().entitiesByType("Player");

	if(!allPlayers.empty())
	{
		Entity player = allPlayers.at(0);

		CController& cont  = player.getComponent<CController>();
		CMovement&   move  = player.getComponent<CMovement>();
		CTransform&  trans = player.getComponent<CTransform>();

		trans.previousPosition = trans.currentPosition;
		trans.currentPosition += (trans.velocity * cont.directions);

		playerMovement(cont, move);
	}
}

// private
void Movement::playerMovement(CController& cont, CMovement& move)
{
	cont.directions = {0.0f, 0.0f};

	switch(cont.keyCount)
	{
		case 1:
			oneKey(cont, move);
		break;
		case 2:
			twoKeys(cont, move);
		break;
		case 3:
			threeKeys(cont, move);
		break;
	}
}


void Movement::oneKey(CController& cont, CMovement& move)
{
	if(cont.down)
  {
    cont.directions += move.down();
  }

	if(cont.left)
  {
    cont.directions += move.left();
  }

	if(cont.right)
  {
   cont.directions += move.right();
  }

  if(cont.up)
  {
    cont.directions += move.up();
  }
}


void Movement::twoKeys(CController& cont, CMovement& move)
{
	Vec2 dig = move.diagonal();

  if(cont.down && cont.left)
  {
    cont.directions.x = -dig.x;
		cont.directions.y = dig.y;
  }

  if(cont.down && cont.right)
  {
    cont.directions.x = dig.x;
		cont.directions.y = dig.y;
  }

  if(cont.up && cont.left)
  {
    cont.directions.x = -dig.x;
		cont.directions.y = -dig.y;
  }

  if(cont.up && cont.right)
  {
    cont.directions.x = dig.x;
		cont.directions.y = -dig.y;
  }
}


void Movement::threeKeys(CController& cont, CMovement& move)
{
  if(cont.up && cont.left && cont.right)
  {
    cont.directions = move.up();
  }

  if(cont.down && cont.left && cont.right)
  {
    cont.directions = move.down();
  }

  if(cont.left && cont.down && cont.up)
  {
    cont.directions = move.left();
  }

  if(cont.right && cont.down&& cont.up)
  {
    cont.directions = move.right();
  }
}