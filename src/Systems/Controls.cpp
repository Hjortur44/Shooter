#include "Controls.h"

Controls::Controls() {}

Controls::~Controls() {}


bool Controls::isRequestingUp()
{
  return Input::Instance().isKey(sf::Keyboard::W);
}


bool Controls::isRequestingDown()
{
  return Input::Instance().isKey(sf::Keyboard::S);
}


bool Controls::isRequestingLeft()
{
  return Input::Instance().isKey(sf::Keyboard::A);
}


bool Controls::isRequestingRight()
{
  return Input::Instance().isKey(sf::Keyboard::D);
}


bool Controls::isRequestingShoot()
{
  return Input::Instance().isKey(sf::Keyboard::G);
}


bool Controls::isRequestingDestroy()
{
  return Input::Instance().isKey(sf::Keyboard::H);
}
