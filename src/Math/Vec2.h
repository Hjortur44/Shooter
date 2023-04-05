#pragma once

#include <cstddef>

class Vec2
{
    int m_x = 0;
    int m_y = 0;

  public:
    Vec2();
    Vec2(int x, int y);

    Vec2 operator + (const Vec2& rhs) const;
    Vec2 operator - (const Vec2& rhs) const;
    Vec2 operator * (const int val) const;
    Vec2 operator / (const int val) const;

    bool operator == (const Vec2& rhs) const;
    bool operator != (const Vec2& rhs) const;

    void operator += (const Vec2& rhs);
    void operator -= (const Vec2& rhs);
    void operator *= (const int val);
    void operator /= (const int val);

    Vec2 normalize(const Vec2& lhs, const Vec2& rhs);

    int dist(const Vec2& rhs);
    int lengtSQ(const Vec2& rhs);

    const int getX() const;
    const int getY() const;
};