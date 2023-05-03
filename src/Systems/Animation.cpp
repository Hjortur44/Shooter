#include "Animation.h"


Animation::Animation(const std::string &name, const sf::Texture &t):m_name(name)
{
    m_sprite.setTexture(t);
    m_size = Vec2((float)t.getSize().x, (float)t.getSize().y);
    m_sprite.setOrigin(m_size.x/2.0f,m_size.y/2.0f);
    m_sprite.setTextureRect(sf::IntRect(0,0,m_size.x,m_size.y));
}


Animation::Animation(const std::string &name, const sf::Texture &t, size_t frameCount, size_t speed):m_name(name),m_frameCount(frameCount),m_speed(speed)
{
    m_sprite.setTexture(t);
    m_size = Vec2((float )t.getSize().x / frameCount, (float)t.getSize().y);
    m_sprite.setOrigin(m_size.x/2.0f,m_size.y/2.0f);
    m_sprite.setTextureRect(sf::IntRect(std::floor(m_currentFrame)* m_size.x,0,m_size.x,m_size.y));
}


void Animation::update()
{
    m_currentFrame++;
    //TODO: calc the correct frame of animation to play based on currentframe and speed
    size_t frame = (m_currentFrame / m_speed) % m_frameCount;
    const auto FW = m_size.x/m_frameCount;
    const auto FH = m_size.y/m_frameCount;
    const auto rectangle = sf::IntRect (frame * FW, 0, FW,FH);
    m_sprite.setTextureRect(rectangle);
    //set the current texture rectangle properly -> see constructor.
}


const bool Animation::hasEnded() const
{
  return false;
}


const sf::Sprite& Animation::sprite() const
{
	return m_sprite;
}


const std::string& Animation::name() const
{
	return m_name;
}


const Vec2& Animation::size() const
{
	return m_size;
}