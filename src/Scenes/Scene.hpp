#pragma once

#include "../Managers/AssetManager.hpp"
#include "../Managers/EntityManager.hpp"
#include "../Math/Vec2.hpp"

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

class Scene
{
public:
  ~Scene();

	virtual void update() = 0;
};
