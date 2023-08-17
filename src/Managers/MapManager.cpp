#include "MapManager.h"

MapManager& MapManager::Instance()
{
  static MapManager INSTANCE;
  return INSTANCE;
}


const	std::map<std::string, std::vector<Vec2>>& MapManager::mapTexturesAndLocations(const int number) const
{
	return m_map.at(number);
}


void MapManager::analizeMapConfigs(const std::map<int, std::string> map)
{
	for(const auto& [key, value] : map)
	{
		std::ifstream fMapName(value);

		if(fMapName.is_open())
		{
			int isPassable = 0;

			std::string textureName      = "<Name>";
			std::string textureLocations = "<Location>";

			std::map<std::string, std::vector<Vec2>> currentMap;

			while(fMapName >> textureName)
			{
				fMapName >> isPassable >> textureLocations;

				std::vector<Vec2> locations;

				std::ifstream fLocations(textureLocations);

				if(fLocations.is_open())
				{
					float x = 0.0f;
					float y = 0.0f;

					while(fLocations.good())
					{
						fLocations >> y >> x;

						locations.push_back(Vec2(x * 32, y * 32));
					}

					currentMap[textureName] = locations;
				}
				else
					std::cout << "Could not open the location file: " << textureLocations << " for the map: " << value << std::endl;

				fLocations.close();
			}

			m_map[key] = currentMap;
		}
		else
			std::cout << "Could not open this map file: " << value << std::endl;

		fMapName.close();
	}
}


// private
MapManager::MapManager() {}
