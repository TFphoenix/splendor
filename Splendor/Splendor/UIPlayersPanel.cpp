#include "UIPlayersPanel.h"
#include "Player.h"

UIPlayersPanel::UIPlayersPanel(std::vector<Player>* pPlayers, const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("PlayersPanel", size, position)
{
	// Player panels
	uint16_t iterator = 0;
	UIPlayerPanel::LoadIconTextures();
	UIPlayerPanel::ShuffleTextures();
	for (auto& player : *pPlayers)
	{
		m_playerPanels[iterator].emplace(&player, sf::Vector2f(position.x, position.y + (iterator + 1) * s_paddingPercentage * size.y + iterator * s_panelPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
		m_playerPanels[iterator].value().SetUserTexture(iterator);
		++iterator;
	}
	m_playerPointerSize = iterator;

	// Instantiate Player Pointer
	sf::Texture* playerPointerTexture = new sf::Texture;
	playerPointerTexture->loadFromFile(s_playerPointerFile);
	m_playerPointer.setTexture(playerPointerTexture);
	const float playerPointerSize = m_playerPanels[0]->getSize().y - 2 * s_playerPointerPadding * m_playerPanels[0]->getSize().y;
	m_playerPointer.setSize(sf::Vector2f(playerPointerSize, playerPointerSize));
	for (const auto& panel : m_playerPanels)
	{
		m_playerPointerPositions.push_back(panel->getPosition().y + s_playerPointerPadding * panel->getSize().y);
	}
	m_playerPointerIterator = 0;
	m_playerPointer.setPosition(getPosition().x, m_playerPointerPositions[m_playerPointerIterator]);

	// Add drawable content
	for (auto& panel : m_playerPanels)
	{
		if (panel.has_value())
			AddContent(dynamic_cast<sf::Drawable*>(&panel.value()));
	}
	AddContent(dynamic_cast<sf::Drawable*>(&m_playerPointer));

	// Add collider content
	for (auto& panel : m_playerPanels)
	{
		if (panel.has_value())
			AddContent(dynamic_cast<Collider*>(&panel.value()));
	}
}

UIPlayerPanel* UIPlayersPanel::GetIfTriggered()
{
	UIPlayerPanel* triggeredPanel = nullptr;
	for (auto& panel : m_playerPanels)
	{
		if (panel.has_value())
		{
			if (panel->GetTriggered())
			{
				triggeredPanel = &panel.value();
			}
			panel->SetTriggered(false);
		}
	}
	return triggeredPanel;
}

void UIPlayersPanel::pointToNextPlayer()
{
	++m_playerPointerIterator;
	if (m_playerPointerIterator == m_playerPointerSize)
		m_playerPointerIterator = 0;
	m_playerPointer.setPosition(getPosition().x, m_playerPointerPositions[m_playerPointerIterator]);
}
