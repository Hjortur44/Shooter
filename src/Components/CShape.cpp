#include "Components.h"

CShape::CShape() {}

CShape::CShape(const Vec2& shape, const Vec2& position, const sf::Texture& texture, bool active)
 : circle(shape.x, shape.y), shape(shape), position(position), active(active)
{
  circle.setOrigin(shape.x, shape.y);
  circle.setPosition(position.x, position.y);
  circle.setTexture(&texture);
}
