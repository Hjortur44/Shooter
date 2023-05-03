#include "Scene.h"

Scene::Scene() {}

Scene::~Scene() {}

const ActionMap& Scene::actionMap() const
{
	return m_actionMap;
}


void Scene::registerAction(int inputKey, const std::string& actionName)
{
  m_actionMap[inputKey] = actionName;
}