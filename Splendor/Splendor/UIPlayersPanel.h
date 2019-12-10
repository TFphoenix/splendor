#pragma once
#include "UIPanel.h"
#include "UIPlayerPanel.h"
#include <optional>

class UIPlayersPanel :public UIPanel
{
public:
	UIPlayersPanel(uint16_t playerCount, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

private:
	static inline const float s_paddingPercentage = 0.04f;
	static inline const float s_panelPercentage = 0.2f;

private:
	std::array<std::optional<UIPlayerPanel>, 4> m_playerPanels;

};
