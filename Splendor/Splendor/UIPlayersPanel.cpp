#include "UIPlayersPanel.h"

UIPlayersPanel::UIPlayersPanel(uint16_t playerCount, const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("PlayersPanel", size, position)
{
	// Player panels
	uint16_t iterator = 0;
	UIPlayerPanel::LoadIconTextures();
	UIPlayerPanel::ShuffleTextures();
	while (playerCount--)
	{
		m_playerPanels[iterator].emplace(UIPlayerPanel::Type::User, sf::Vector2f(position.x, position.y + (iterator + 1) * s_paddingPercentage * size.y + iterator * s_panelPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
		m_playerPanels[iterator].value().SetUserTexture(iterator);
		++iterator;
	}

	// Add drawable content
	for (auto& panel : m_playerPanels)
	{
		if (panel.has_value())
			AddContent(dynamic_cast<sf::Drawable*>(&panel.value()));
	}

	// Add collider content
	for (auto& panel : m_playerPanels)
	{
		if (panel.has_value())
			AddContent(dynamic_cast<Collider*>(&panel.value()));
	}
}