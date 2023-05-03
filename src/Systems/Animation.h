#include "../Math/Vec2.h"

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(const std::string & name, const sf::Texture & t);
	Animation(const std::string & name, const sf::Texture & t, size_t frameCount,size_t speed);

	const bool hasEnded() const;

	const sf::Sprite& sprite() const;

	const std::string& name() const;

	const Vec2& size() const;

	void update();

private:
	sf::Sprite m_sprite;

	Vec2 m_size = {1,1};

	std::string m_name = "none";

	size_t m_frameCount = 0;
	size_t m_currentFrame = 0;
	size_t m_speed = 0;
};