#include "Controls.h"

Controls::Controls() {}

Controls::~Controls() {}

bool Controls::isRequestingUp()
{
	return m_input.isKey(sf::Keyboard::W);
}

bool Controls::isRequestingDown()
{
	return m_input.isKey(sf::Keyboard::S);
}

bool Controls::isRequestingLeft()
{
	return m_input.isKey(sf::Keyboard::A);
}

bool Controls::isRequestingRight()
{
	return m_input.isKey(sf::Keyboard::D);
}

bool Controls::isRequestingShoot()
{
	return m_input.isKey(sf::Keyboard::G);
}

bool Controls::isRequestingDestroy()
{
	return m_input.isKey(sf::Keyboard::H);
}