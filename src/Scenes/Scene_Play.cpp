#include "Scene_Play.h"

Scene_Play::Scene_Play(const std::string& levelPath)
  : Scene(), m_levelPath(levelPath)
{
  init(m_levelPath);
}


Scene_Play::~Scene_Play() {}


void Scene_Play::update()
{

}


void Scene_Play::sRender()
{

}


void Scene_Play::onEnd()
{

}


void Scene_Play::sDoAction(const Action& action)
{

}

// private
void Scene_Play::init(const std::string& levelPath)
{
  registerAction(sf::Keyboard::Escape, "QUIT");
  registerAction(sf::Keyboard::P,      "PAUSE");
  registerAction(sf::Keyboard::W,      "UP");
  registerAction(sf::Keyboard::S,      "DOWN");
  registerAction(sf::Keyboard::A,      "LEFT");
  registerAction(sf::Keyboard::D,      "RIGHT");
}

void Scene_Play::loadLevel(const std::string& levelPath)
{

}