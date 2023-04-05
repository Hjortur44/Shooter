#include "Scene.h"

Scene::Scene() {}
Scene::~Scene() {}

void Scene::registerAction(int inputKey, const std::string& actionName)
{
  m_actionMap[inputKey] = actionName;
}