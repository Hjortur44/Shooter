#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


sf::RenderWindow& GameEngine::window()
{
  return m_window;
}


void GameEngine::run()
{
  while(m_window.isOpen())
  {
    update();
  }
}


void GameEngine::quit()
{
  m_window.close();
}


void GameEngine::update()
{
	m_physics.collision();
  EntityManager::Instance().update();

  sUserInput();
  sBulletSpawner();
  sMovement();
  sRender();
}


// private
void GameEngine::init()
{
  m_window.create(sf::VideoMode(640, 480), "Game");
  m_window.setFramerateLimit(60);
}


void GameEngine::sMovement()
{
  m_movement.moving();
}


void GameEngine::sEnemySpawner()
{
}


void GameEngine::sBulletSpawner()
{
  m_bulletSpawn.shoot();
}


void GameEngine::sUserInput()
{
  sf::Event event;

  while(m_window.pollEvent(event))
  {
    if(event.type == sf::Event::KeyPressed)
      Input::Instance().keyPressed(event.key.code);

    if(event.type == sf::Event::KeyReleased)
      Input::Instance().keyReleased(event.key.code);

    if(event.type == sf::Event::Closed)
      quit();
  }


  /*
    if(currentScene()->getActionMap().find(event.key.code) != currentScene()->getActionMap().end())
    {
      const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";
      currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), actionType));
    }
  */
}


void GameEngine::sRender()
{
  const std::vector<bool>& actives = ComponentMemoryPool::Instance().getActives();
  std::vector<CShape>&     shapes  = ComponentMemoryPool::Instance().getComponentVector<CShape>();

  m_window.clear();

  for(int i = 0; i < actives.size(); i++)
  {
    if(actives[i])
      m_window.draw(shapes[i].circle);

  }

  m_window.display();
}
