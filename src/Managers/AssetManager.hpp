#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <vector>

class AssetManager
{
public:
  AssetManager(AssetManager&) = delete;

  static AssetManager& Instance();

  const sf::Texture& textures(const std::string& name) const;

  void update(const std::vector<std::string>& texture_names, const std::vector<std::string>& assets);

private:
	AssetManager();

	std::map<std::string, sf::Texture> m_textures;
};
