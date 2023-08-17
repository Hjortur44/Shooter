#include "Controller.h"

Controller::Controller() {}

Controller::~Controller() {}

void Controller::keyPressed(int key)
{
	Input::Instance().keyPressed(key);
}


void Controller::keyReleased(int key)
{
	Input::Instance().keyReleased(key);
}


void Controller::update()
{
	EntityComponentsManager& compManager = EntityComponentsManager::Instance();
	const std::vector<Entity>& ents = compManager.entitiesByType("Player");

	if(!ents.empty())
	{
		Entity player = ents.at(0);
		CController& cont = player.getComponent<CController>();
		Input& input = Input::Instance();

		cont.down  = false;
		cont.left  = false;
		cont.right = false;
		cont.up    = false;

		switch(input.keyCount())
		{
			case 1:
				oneKey(input, cont);
			break;
			case 2:
				twoKeys(input, cont);
			break;
			case 3:
				threeKeys(input, cont);
			break;
			default:
				input.keyCountReset();
		}

		cont.keyCount = input.keyCount();
	}
}

// private
void Controller::oneKey(Input& input, CController& cont)
{
	if(input.isKey(18))
  {
   	cont.down = true;
  }

	if(input.isKey(0))
  {
    cont.left = true;
  }

	if(input.isKey(3))
  {
    cont.right = true;
  }

  if(input.isKey(22))
  {
		cont.up = true;
  }
}

void Controller::twoKeys(Input& input, CController& cont)
{

  if(input.isKey(18) && input.isKey(0))
  {
   	cont.down = true;
    cont.left = true;
  }

  if(input.isKey(18) && input.isKey(3))
  {
   	cont.down  = true;
    cont.right = true;
  }

  if(input.isKey(22) && input.isKey(0))
  {
		cont.up   = true;
    cont.left = true;
  }

  if(input.isKey(22) && input.isKey(3))
  {
		cont.up    = true;
    cont.right = true;
  }
}

void Controller::threeKeys(Input& input, CController& cont)
{
  if(input.isKey(22) && input.isKey(0) && input.isKey(3))
  {
		cont.up    = true;
    cont.left  = true;
    cont.right = true;
  }

  if(input.isKey(18) && input.isKey(0) && input.isKey(3))
  {
		cont.down  = true;
    cont.left  = true;
    cont.right = true;
  }

  if(input.isKey(0) && input.isKey(18) && input.isKey(22))
  {
		cont.left = true;
    cont.down = true;
    cont.up   = true;
  }

  if(input.isKey(3) && input.isKey(18) && input.isKey(22))
  {
		cont.right = true;
    cont.down  = true;
    cont.up    = true;
  }
}
