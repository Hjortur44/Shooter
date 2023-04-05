#include "Scene_Menu.h"

Scene_Menu::Scene_Menu(const std::string& title)
  : Scene(), m_title(title)
{
	init();
}

Scene_Menu::~Scene_Menu() {}


void Scene_Menu::sDoAction(const Action& action)
{
  if(action.getType() == "START")
  {
    if(action.getName() == "UP")
    {

    }
    else if(action.getName() == "DOWN")
    {

    }
    else if(action.getName() == "PLAY")
    {

    }
    else if(action.getName() == "QUIT")
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
