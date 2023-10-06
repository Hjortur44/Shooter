#pragma once

#include "../Managers/AssetManager.h"
#include "../Managers/EntityComponentsManager.h"

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
