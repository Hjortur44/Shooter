#include "Vec2.hpp"

Vec2::Vec2() {}

Vec2::Vec2(float x, float y) : m_x(x), m_y(y) {}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
  return Vec2(m_x + rhs.x(), m_y + rhs.y());
}


Vec2 Vec2::operator + (const float val) const
{
  return Vec2(m_x + val, m_y + val);
}


Vec2 Vec2::operator - (const Vec2& rhs) const
{
  return Vec2(m_x - rhs.x(), m_y - rhs.y());
}


Vec2 Vec2::operator - (const float val) const
{
  return Vec2(m_x - val, m_y - val);
}


Vec2 Vec2::operator * (const Vec2& rhs) const
{
	return Vec2(m_x * rhs.x(), m_y * rhs.y());
}


Vec2 Vec2::operator * (const float val) const
{
  return Vec2(m_x * val, m_y * val);
}


Vec2 Vec2::operator / (const float val) const
{
  if(val == 0)
    return Vec2(0, 0);

  return Vec2(m_x / val, m_y / val);
}

void Vec2::operator += (const Vec2& rhs)
{
  m_x += rhs.x();
  m_y += rhs.y();
}


void Vec2::operator -= (const Vec2& rhs)
{
  m_x -= rhs.x();
  m_y -= rhs.y();
}


void Vec2::operator *= (const Vec2& rhs)
{
  m_x *= rhs.x();
  m_y *= rhs.y();
}


void Vec2::operator *= (const float val)
{
  m_x *= val;
  m_y *= val;
}


void Vec2::operator /= (const float val)
{
  if(val == 0)
  {
    m_x = 0;
    m_y = 0;
  }
  else
  {
    m_x /= val;
    m_y /= val;
  }
}


bool Vec2::operator < (const float val) const
{
  return (m_x < val && m_y < val);
}


bool Vec2::operator > (const float val) const
{
  return (m_x > val && m_y > val);
}


bool Vec2::operator < (const Vec2& rhs) const
{
  return (m_x < rhs.x() && m_y < rhs.y());
}


bool Vec2::operator > (const Vec2& rhs) const
{
  return (m_x > rhs.x() && m_y > rhs.y());
}


bool Vec2::operator >= (const float val) const
{
  return (m_x >= val && m_y >= val);
}


bool Vec2::operator <= (const float val) const
{
  return (m_x <= val && m_y <= val);
}


bool Vec2::operator == (const float val) const
{
  return (m_x == val && m_y == val);
}


bool Vec2::operator != (const float val) const
{
  return (m_x != val && m_y != val);
}


bool Vec2::operator == (const Vec2& rhs) const
{
  return (m_x == rhs.x() && m_y == rhs.y());
}


bool Vec2::operator != (const Vec2& rhs) const
{
  return (m_x != rhs.x() && m_y != rhs.y());
}


const float Vec2::dist(const Vec2& rhs)
{
  return 0.0f;
}


const float Vec2::x() const
{
	return m_x;
}


const float Vec2::y() const
{
	return m_y;
}


const float Vec2::lengtSQ(const Vec2& rhs)
{
  float dm_x = m_x - rhs.x();
  float dm_y = m_y - rhs.y();
  float sq = (dm_x * dm_x) + (dm_y * dm_y);

  return sq;
}


const Vec2 Vec2::normalizeSQ(const Vec2& rhs)
{
  float dm_x = (m_x - rhs.x()) * (m_x - rhs.x());
  float dm_y = (m_y - rhs.y()) * (m_y - rhs.y());
  float sq = dm_x + dm_y;
  float nm_x = dm_x / sq;
  float nm_y = dm_y / sq;

  return Vec2(nm_x, nm_y);
}


void Vec2::normalizeTri(const Vec2& rhs)
{
/*
	const double pi = std::acos(-1);
	float m_y = 4.0f;
	float m_x = 4.0f;

	float theta = atan2f(m_y, m_x);
	float m_ys =  std::sin(theta);
	float m_xc = std::cos(theta);
	float t = tan(theta);

	// deg = rad * 180 / pi
	float rad = pi / 180.0f; // one rad
	float deg = theta * 180.0f / pi; // one deg, rad = pi / 180
*/
}