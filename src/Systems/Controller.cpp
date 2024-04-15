#include "Controller.hpp"

Controller::Controller() {}
Controller::~Controller() {}

const Vec2 Controller::requestDiagonal() const
{
	return m_diagonal;
}


const Vec2 Controller::requestDown() const
{
	return m_down;
}


const Vec2 Controller::requestLeft() const
{
	return m_left;
}


const Vec2 Controller::requestRight() const
{
	return m_right;
}


const Vec2 Controller::requestUp() const
{
	return m_up;
}