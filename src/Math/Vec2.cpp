#include "Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
  return Vec2(x + rhs.x, y + rhs.y);
}


Vec2 Vec2::operator - (const Vec2& rhs) const
{
  return Vec2(x - rhs.x, y - rhs.y);
}


Vec2 Vec2::operator * (const Vec2& rhs) const
{
	return Vec2(x * rhs.x, y * rhs.y);
}


Vec2 Vec2::operator * (const float val) const
{
  return Vec2(x * val, y * val);
}


Vec2 Vec2::operator / (const float val) const
{
  if(val == 0)
    return Vec2(0, 0);

  return Vec2(x / val, y / val);
}


bool Vec2::operator == (const Vec2& rhs) const
{
  return (x == rhs.x && y == rhs.y);
}


bool Vec2::operator != (const Vec2& rhs) const
{
  return (x != rhs.x && y != rhs.y);
}


void Vec2::operator += (const Vec2& rhs)
{
  x += rhs.x;
  y += rhs.y;
}


void Vec2::operator -= (const Vec2& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
}


void Vec2::operator *= (const Vec2& rhs)
{
  x *= rhs.x;
  y *= rhs.y;
}


void Vec2::operator *= (const float val)
{
  x *= val;
  y *= val;
}


void Vec2::operator /= (const float val)
{
  if(val == 0)
  {
    x = 0;
    y = 0;
  }
  else
  {
    x /= val;
    y /= val;
  }
}


float Vec2::dist(const Vec2& rhs)
{
  return 0.0f;
}


Vec2 Vec2::normalize(const Vec2& lhs, const Vec2& rhs)
{
  float dx = lhs.x - rhs.x;
  float dy = lhs.y - rhs.y;

  float sq = (dx * dx) + (dy * dy);


  float nx = sqrt((dx * dx) / sq);
  float ny = sqrt((dy * dy) / sq);

  return Vec2(nx, ny);
}


float Vec2::lengtSQ(const Vec2& rhs)
{
  float dx = x - rhs.x;
  float dy = y - rhs.y;
  float sq = (dx * dx) + (dy * dy);

  return sq;
}
