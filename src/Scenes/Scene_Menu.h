#pragma once

#include "Scene.h"

class Scene_Menu : public Scene
{
  std::vector<std::string>  m_menuStrings;
  std::vector<std::string>  m_levelPaths;

  std::string               m_title              =  "";
  size_t                    m_selectedMenuIndex  =  0;

  void init();

  public:
    Scene_Menu(const std::string& m_title);
    ~Scene_Menu();

   void onEnd();
   void update();
   void sDoAction(const Action& action);
   void sRender();
};