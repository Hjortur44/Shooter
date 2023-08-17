#pragma once

#include "Scene.h"

class Scene_Menu : public Scene
{
public:
  Scene_Menu(const std::string& m_title);
  ~Scene_Menu();

 void update();
};
