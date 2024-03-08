#pragma once

#include "../Math/Vec2.hpp"

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

class Scene
{
public:
  virtual ~Scene();

	virtual void update() = 0;
};
