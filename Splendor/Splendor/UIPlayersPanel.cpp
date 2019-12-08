#include "UIPlayersPanel.h"

UIPlayersPanel::UIPlayersPanel(const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("PlayersPanel", size, position)
{
	// Player panels
	m_playerPanels[0].emplace(UIPlayerPanel::Type::User, sf::Vector2f(position.x, position.y + s_paddingPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
	m_playerPanels[0].value().SetUserTexture(0);
	m_playerPanels[1].emplace(UIPlayerPanel::Type::User, sf::Vector2f(position.x, position.y + 2 * s_paddingPercentage * size.y + s_panelPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
	m_playerPanels[1].value().SetUserTexture(1);
	m_playerPanels[2].emplace(UIPlayerPanel::Type::User, sf::Vector2f(position.x, position.y + 3 * s_paddingPercentage * size.y + 2 * s_panelPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
	m_playerPanels[2].value().SetUserTexture(2);
	m_playerPanels[3].emplace(UIPlayerPanel::Type::User, sf::Vector2f(position.x, position.y + 4 * s_paddingPercentage * size.y + 3 * s_panelPercentage * size.y), sf::Vector2f(size.x, s_panelPercentage * size.y));
	m_playerPanels[3].value().SetUserTexture(3);

	// Add drawable content
	for (auto& panel : m_playerPanels)
	{
		AddContent(dynamic_cast<sf::Drawable*>(&panel.value()));
	}

	// Add collider content
	for (auto& panel : m_playerPanels)
	{
		AddContent(dynamic_cast<Collider*>(&panel.value()));
	}
}
