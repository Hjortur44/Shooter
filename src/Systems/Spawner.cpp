#include "Spawner.h"

Spawner::Spawner()
{
	m_configMap = m_configManager.getConfigs();
}

Spawner::~Spawner() {}


void Spawner::spawnEntity()
{
	init();
}


// private

void Spawner::init()
{
	if(m_counter < m_compPool.getMaxCapacity())
	{
		const std::string& asset = m_assetManager.getAssets().at("wood");
		m_texture.loadFromFile(asset); // <<-- move this to the Asset class...

		const std::vector<size_t>& ents = m_entityManager.getEntities().at(m_counter++);

		sf::Color fill    = sf::Color(ents.at(6), ents.at(7), ents.at(8));
		sf::Color outline = sf::Color(ents.at(9), ents.at(10), ents.at(11));

		m_compPool.addComponent<CTransform>(ents.at(14), Vec2(ents.at(0), ents.at(1)), Vec2(ents.at(2), ents.at(3)));
		m_compPool.addComponent<CShape>(ents.at(14), ents.at(4), ents.at(5), Vec2( ents.at(0), ents.at(1)), fill, outline, ents.at(12), m_texture);
		m_compPool.addComponent<CCollision>(ents.at(14), ents.at(4));
		m_compPool.addComponent<CLifespan>(ents.at(14), ents.at(13));
	}
}