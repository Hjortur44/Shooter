#include "Action.h"

Action::Action(const std::string& name, const std::string& type)
  : m_name(name), m_type(type) {}

Action::~Action() {}

const bool Action::hasEnded() const
{
    return m_isAction;
}

const std::string& Action::name() const
{
  return m_name;
}


const std::string& Action::type() const
{
  return m_type;
}

void Action::endAction()
{
	m_isAction = false;
}


void Action::startAction()
{
	m_isAction = true;
}


void Action::update()
{
}
