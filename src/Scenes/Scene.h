#pragma once

#include "../Math/Vec2.h"
#include "../Systems/Spawner.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class Scene
{
public:
  Scene();
  ~Scene();

protected:
	Spawner m_spawner = {32};
};
