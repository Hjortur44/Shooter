#include "Components.h"

CShape::CShape() {}

CShape::CShape(const Vec2& shape, const Vec2& position, const sf::Texture& texture, bool active)
 : rectangle(sf::Vector2f(shape.x, shape.y)), position(position), active(active)
{
  rectangle.setOrigin(shape.x / 2, shape.y / 2);
  rectangle.setPosition(position.x, position.y);
  rectangle.setTexture(&texture);
	rectangle.setRotation(0);
}
