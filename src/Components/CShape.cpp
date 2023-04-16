#include "Components.h"

CShape::CShape() {}

CShape::CShape(Vec2 shape, Vec2 position, const sf::Texture& texture)
 : circle(shape.x, shape.y)
{
  circle.setOrigin(shape.x, shape.y);
  circle.setPosition(position.x, position.y);
  circle.setTexture(&texture);
}
