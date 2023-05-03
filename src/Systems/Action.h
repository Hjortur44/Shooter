#pragma once

#include <string>

class Action
{
public:
  Action(const std::string& name, const std::string& type);
  ~Action();

  const std::string& name() const;
  const std::string& type() const;

	const bool hasEnded() const;

  void endAction();
  void startAction();
  void update();

private:
	bool m_isAction = false;

  std::string m_name = "NONE";
  std::string m_type = "NONE";
};
