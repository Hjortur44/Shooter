#pragma once

#include <cmath>
#include <ostream>

class Vec2
{
public:
  Vec2();
  Vec2(float x, float y);

  Vec2 operator + (const Vec2& rhs) const;
  Vec2 operator - (const Vec2& rhs) const;
  Vec2 operator * (const Vec2& rhs) const;
  Vec2 operator * (const float val) const;
  Vec2 operator / (const float val) const;

  bool operator == (const Vec2& rhs) const;
  bool operator != (const Vec2& rhs) const;

  void operator += (const Vec2& rhs);
  void operator -= (const Vec2& rhs);
  void operator *= (const Vec2& rhs);
  void operator *= (const float val);
  void operator /= (const float val);

  Vec2 normalizeSQ(const Vec2& rhs);
	void normalizeTri(const Vec2& rhs);

  float dist(const Vec2& rhs);
  float lengtSQ(const Vec2& rhs);

  float x = 0;
  float y = 0;

	friend std::ostream& operator << (std::ostream& stream, const Vec2& vector)
	{
		return stream << vector.x << " " << vector.y << "\n";
	}
};
