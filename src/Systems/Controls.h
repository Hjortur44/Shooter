#pragma once

#include "Input.h"

#include <SFML/Graphics.hpp>

class Controls
{
  Input& m_input = Input::Instance();

public:
  Controls();
  ~Controls();

  bool isRequestingUp();
  bool isRequestingDown();
  bool isRequestingLeft();
  bool isRequestingRight();
  bool isRequestingShoot();

  bool isRequestingDestroy();
};
