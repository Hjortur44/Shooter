#pragma once

#include "../Math/Vec2.hpp"
#include <iostream>

class Component
{
public:
	virtual	~Component() = 0;

	virtual const bool active() = 0;

	virtual void activate(const bool activate) = 0;
};