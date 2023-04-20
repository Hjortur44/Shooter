#pragma once

#include <iostream>
#include <string>

class Action
{
public:
  Action(const std::string& type, const std::string& name);
  ~Action();

  const std::string& getName() const;
  const std::string& getType() const;

private:
  std::string m_name = "NONE";
  std::string m_type = "NONE";
};
