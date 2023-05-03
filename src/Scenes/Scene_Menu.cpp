#include "Scene_Menu.h"

Scene_Menu::Scene_Menu(const std::string& title)
  : Scene(), m_title(title)
{
  init();
}

Scene_Menu::~Scene_Menu() {}


void Scene_Menu::sDoAction(const Action& action)
{
  if(action.type() == "START")
  {
    if(action.name() == "UP")
    {

    }
    else if(action.name() == "DOWN")
    {

    }
    else if(action.name() == "PLAY")
    {

    }
    else if(action.name() == "QUIT")
    {
      onEnd();
    }
  }
}

void Scene_Menu::update()
{

}

void Scene_Menu::sRender()
{
}


void Scene_Menu::onEnd()
{
  // quit the game...
}


// private
void Scene_Menu::init()
{
  registerAction(sf::Keyboard::W,       "UP");
  registerAction(sf::Keyboard::S,       "DOWN");
  registerAction(sf::Keyboard::D,       "PLAY");
  registerAction(sf::Keyboard::Escape,  "QUIT");
}
