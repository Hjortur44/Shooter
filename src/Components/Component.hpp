#pragma once

#include "../Math/Vec2.hpp"

#include <SFML/Graphics.hpp>

class Component
{
public:
	~Component();

	virtual const bool alive() = 0;

	virtual void active(const bool activate) = 0;

protected:
	bool m_alive = false;
};