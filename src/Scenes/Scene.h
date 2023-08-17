#pragma once

#include "../Math/Vec2.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Scene
{
public:
  Scene();
  ~Scene();

	virtual void update() = 0;
};
