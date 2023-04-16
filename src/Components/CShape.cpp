#include "Components.h"

CShape::CShape() {}

CShape::CShape
(
  Vec2 shape, Vec2 position, const sf::Texture& texture
)  : m_circle(shape.getX(), shape.getY())
{
  m_circle.setOrigin(shape.getX(), shape.getY());
  m_circle.setPosition(position.getX(), position.getY());
  m_circle.setTexture(&texture);
}


sf::CircleShape CShape::getCircle()
{
  return m_circle;
}
