#include "Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(int x, int y) : m_x(x), m_y(y) {}


Vec2 Vec2::operator + (const Vec2& rhs) const
{
  return Vec2(m_x + rhs.getX(), m_y + rhs.getY());
}


Vec2 Vec2::operator - (const Vec2& rhs) const
{
  return Vec2(m_x - rhs.getX(), m_y - rhs.getY());
}


Vec2 Vec2::operator * (const int val) const
{
  return Vec2(m_x * val, m_y * val);
}


Vec2 Vec2::operator / (const int val) const
{
  if(val == 0)
    return Vec2(0, 0);

  return Vec2(m_x / val, m_y / val);
}


bool Vec2::operator == (const Vec2& rhs) const
{
  return (m_x == rhs.getX() && m_y == rhs.getY());
}


bool Vec2::operator != (const Vec2& rhs) const
{
  return (m_x != rhs.getX() && m_y != rhs.getY());
}


void Vec2::operator += (const Vec2& rhs)
{
  m_x += rhs.getX();
  m_y += rhs.getY();
}


void Vec2::operator -= (const Vec2& rhs)
{
  m_x -= rhs.getX();
  m_y -= rhs.getY();
}


void Vec2::operator *= (const int val)
{
  m_x *= val;
  m_y *= val;
}


void Vec2::operator /= (const int val)
{
  if(val == 0)
  {
    m_x = 0;
    m_y = 0;
  } else {
    m_x /= val;
  	m_y /= val;
  }
}


int Vec2::dist(const Vec2& rhs)
{
  return 0;
}


Vec2 Vec2::normalize(const Vec2& lhs, const Vec2& rhs)
{
	int l = lengtSQ(rhs);
	int dx = lhs.getX() - rhs.getX();
	int dy = lhs.getY() - rhs.getY();

	int nx = (dx * dx) / l;
	int ny = (dy * dy) / l;

  return Vec2(nx, ny);
}


int Vec2::lengtSQ(const Vec2& rhs)
{
	int dx = m_x - rhs.getX();
	int dy = m_y - rhs.getY();
	int sq = (dx * dx) + (dy * dy);

	return sq;
}


const int Vec2::getX() const
{
  return m_x;
}


const int Vec2::getY() const
{
  return m_y;
}