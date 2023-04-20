#pragma once

#include "Scene.h"

class Scene_Menu : public Scene
{
public:
  Scene_Menu(const std::string& m_title);
  ~Scene_Menu();

  void onEnd();
  void update();

  void sDoAction(const Action& action);
  void sRender();

private:
  void init();

  std::vector<std::string> m_levelPaths;
  std::vector<std::string> m_menuStrings;

  std::string m_title = "";

  int m_selectedMenuIndex = 0;
};
