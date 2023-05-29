#include "Components.h"

CTexture::CTexture() {}

CTexture::CTexture(const std::string& name, bool activate) : name(name), isActive(activate) {}