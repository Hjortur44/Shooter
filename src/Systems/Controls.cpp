#include "Controls.h"

Controls::Controls() {}

Controls::~Controls() {}


bool Controls::isRequestingDown()
{
	return m_input.isKey(18);
}


bool Controls::isRequestingLeft()
{
	return m_input.isKey(0);
}


bool Controls::isRequestingRight()
{
	return m_input.isKey(3);
}


bool Controls::isRequestingUp()
{
	return m_input.isKey(22);
}


bool Controls::isRequestingShoot()
{
	return m_input.isKey(6);
}