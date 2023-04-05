#include "Action.h"

Action::Action(const std::string& type, const std::string& name)
	: m_type(type), m_name(name) {}

Action::~Action() {}

const std::string& Action::getType() const
{
  return m_type;
}


const std::string& Action::getName() const
{
  return m_name;
}