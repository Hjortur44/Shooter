#include "Components.h"

CShape::CShape() {}

CShape::CShape
(
	size_t radius, size_t points,
	size_t positionX, size_t positionY,
	const sf::Color& fill, const sf::Color& outline,
	size_t thickness, const sf::Texture& texture, bool active)
		: circle(radius, points), active(active)
{
  circle.setFillColor(fill);
  circle.setOrigin(radius, radius);
  circle.setOutlineColor(outline);
  circle.setOutlineThickness(thickness);
	circle.setPosition(positionX, positionY);
	circle.setTexture(&texture);
}