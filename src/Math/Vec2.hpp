#pragma once

class Vec2
{
public:
  Vec2();
  Vec2(float x, float y);

  Vec2 operator + (const Vec2& rhs) const;
  Vec2 operator + (const float val) const;
  Vec2 operator - (const Vec2& rhs) const;
  Vec2 operator - (const float val) const;
  Vec2 operator * (const Vec2& rhs) const;
  Vec2 operator * (const float val) const;
  Vec2 operator / (const float val) const;

  void operator += (const Vec2& rhs);
  void operator -= (const Vec2& rhs);
  void operator *= (const Vec2& rhs);
  void operator *= (const float val);
  void operator /= (const float val);

  bool operator < (const float val) const;
  bool operator > (const float val) const;
  bool operator < (const Vec2& rhs) const;
  bool operator > (const Vec2& rhs) const;

  bool operator >= (const float val) const;
  bool operator <= (const float val) const;
  bool operator == (const float val) const;
  bool operator != (const float val) const;
  bool operator == (const Vec2& rhs) const;
  bool operator != (const Vec2& rhs) const;

  const Vec2 normalizeSQ(const Vec2& rhs);

	void normalizeTri(const Vec2& rhs);

  const float dist(const Vec2& rhs);
  const float lengtSQ(const Vec2& rhs);
  const float x() const;
  const float y() const;

private:
  float m_x = 0.0f;
  float m_y = 0.0f;
};
