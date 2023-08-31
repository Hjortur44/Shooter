#include "CTexture.h"

CTexture::CTexture() {}

CTexture::CTexture(const sf::Texture& texture, bool activate) : texture(texture), isActive(activate) {}