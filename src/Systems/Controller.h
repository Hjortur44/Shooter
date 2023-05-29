#pragma once

#include "Input.h"
#include "../Entities/Entity.h"
#include "../Managers/ComponentManager.h"

class Controller
{
public:
	Controller();
	~Controller();

	void keyPressed(int key);
	void keyReleased(int key);
	void update();

private:
	void oneKey(Input& input, CController& cont);
	void twoKeys(Input& input, CController& cont);
	void threeKeys(Input& input, CController& cont);
};