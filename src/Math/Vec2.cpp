#include "Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
  return Vec2(x + rhs.x, y + rhs.y);
}


Vec2 Vec2::operator + (const float val) const
{
  return Vec2(x + val, y + val);
}


Vec2 Vec2::operator - (const Vec2& rhs) const
{
  return Vec2(x - rhs.x, y - rhs.y);
}


Vec2 Vec2::operator - (const float val) const
{
  return Vec2(x - val, y - val);
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


bool Vec2::operator < (const float val) const
{
  return (x < val && y < val);
}


bool Vec2::operator > (const float val) const
{
  return (x > val && y > val);
}


bool Vec2::operator < (const Vec2& rhs) const
{
  return (x < rhs.x && y < rhs.y);
}


bool Vec2::operator > (const Vec2& rhs) const
{
  return (x > rhs.x && y > rhs.y);
}


bool Vec2::operator >= (const float val) const
{
  return (x >= val && y >= val);
}


bool Vec2::operator <= (const float val) const
{
  return (x <= val && y <= val);
}


bool Vec2::operator == (const float val) const
{
  return (x == val && y == val);
}


bool Vec2::operator != (const float val) const
{
  return (x != val && y != val);
}


bool Vec2::operator == (const Vec2& rhs) const
{
  return (x == rhs.x && y == rhs.y);
}


bool Vec2::operator != (const Vec2& rhs) const
{
  return (x != rhs.x && y != rhs.y);
}


float Vec2::dist(const Vec2& rhs)
{
  return 0.0f;
}


Vec2 Vec2::normalizeSQ(const Vec2& rhs)
{
  float dx = (x - rhs.x) * (x - rhs.x);
  float dy = (y - rhs.y) * (y - rhs.y);
  float sq = dx + dy;
  float nx = dx / sq;
  float ny = dy / sq;

  return Vec2(nx, ny);
}

void Vec2::normalizeTri(const Vec2& rhs)
{
/*
	const double pi = std::acos(-1);
	float y = 4.0f;
	float x = 4.0f;

	float theta = atan2f(y, x);
	float ys =  std::sin(theta);
	float xc = std::cos(theta);
	float t = tan(theta);

	// deg = rad * 180 / pi
	float rad = pi / 180.0f; // one rad
	float deg = theta * 180.0f / pi; // one deg, rad = pi / 180
*/
}

float Vec2::lengtSQ(const Vec2& rhs)
{
  float dx = x - rhs.x;
  float dy = y - rhs.y;
  float sq = (dx * dx) + (dy * dy);

  return sq;
}
