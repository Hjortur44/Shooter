#pragma once

#include <string>
#include <iostream>

class Action
{
  std::string m_type = "NONE";
  std::string m_name = "NONE";

  public:
    Action(const std::string& type, const std::string& name);
    ~Action();

    const std::string& getType() const;
    const std::string& getName() const;
};