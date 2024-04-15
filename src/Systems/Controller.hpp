#pragma once

#include "../Math/Vec2.hpp"

class Controller
{
public:
	Controller();
	~Controller();

	const Vec2 requestDiagonal() const;
	const Vec2 requestDown() const;
	const Vec2 requestLeft() const;
	const Vec2 requestRight() const;
	const Vec2 requestUp() const;

private:
  const Vec2 m_diagonal = {0.707106781f, 0.707106781f};
  const Vec2 m_down     = {0.0f, 1.0f};
  const Vec2 m_left     = {-1.0f, 0.0f};
  const Vec2 m_right    = {1.0f, 0.0f};
  const Vec2 m_up       = {0.0f, -1.0f};
};