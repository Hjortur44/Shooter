#pragma once

#include "Input.h"

#include <SFML/Graphics.hpp>

class Controls
{
		Input& m_input = Input::Instance();

	public:
		Controls();
		~Controls();

		// directions
		bool isRequestingDown();
		bool isRequestingLeft();
		bool isRequestingRight();
		bool isRequestingUp();

		// other actions
		bool isRequestingShoot();
};