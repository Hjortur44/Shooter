#include "Components.h"

CShape::CShape() {}

CShape::CShape(size_t radius, size_t points, Vec2 position, const sf::Color& fill, const sf::Color& outline, size_t thickness, const sf::Texture& texture)
	: radius(radius), points(points), position(position), fill(fill), outline(outline), thickness(thickness), texture(texture) {}


void CShape::update()
{
	circle.setRadius(radius);
	circle.setPointCount(points);
	circle.setOrigin(radius, radius);
	circle.setPosition(position.getX(), position.getY());
	circle.setFillColor(fill);
	circle.setOutlineColor(outline);
	circle.setOutlineThickness(thickness);
	circle.setRotation(angle);
	circle.setTexture(&texture);
}
