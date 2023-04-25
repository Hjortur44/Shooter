#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


void GameEngine::run()
{
	Spawner s;
	s.spawnEntity("Player");

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
	EntityManager::Instance().update(); // this must be on top

	sUserInput();
	m_movement.playerMovement();

  sRender();
}


// private
void GameEngine::init()
{
  m_window.create(sf::VideoMode(640, 480), "Game");
  m_window.setFramerateLimit(60);
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
  m_window.clear();

	for(Entity e : EntityManager::Instance().entities())
	{
		CShape& shape = e.getComponent<CShape>();
		shape.circle.setPosition(shape.position.x, shape.position.y);
		m_window.draw(shape.circle);
	}

	m_window.display();
}
