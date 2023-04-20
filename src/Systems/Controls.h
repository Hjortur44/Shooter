#pragma once

#include "Input.h"

#include <SFML/Graphics.hpp>

class Controls
{
public:
  Controls();
  ~Controls();

  bool isRequestingDestroy();
  bool isRequestingDown();
  bool isRequestingLeft();
  bool isRequestingRight();
  bool isRequestingShoot();
  bool isRequestingUp();
};
