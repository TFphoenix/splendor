#pragma once
#include <array>

#include "UIPanel.h"
#include "UIButton.h"
#include "UICardsRowPanel.h"
#include "UIHTokensPanel.h"

class UIHandPanel :public UIPanel
{
public:
	UIHandPanel(const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	//-----> ShowHand(UIPlayerPanel* playerPanel, )

private:
	// Backgrounds
	sf::RectangleShape m_cover;
	sf::RectangleShape m_outerBackground;
	sf::RectangleShape m_innerBackground;
	std::array<sf::RectangleShape, 4> m_panelBackgrounds;

	// GUI
	UIButton m_closeButton;
	UICardsRowPanel m_expansionsPanel;
	UICardsRowPanel m_noblesPanel;
	UIHTokensPanel m_tokensPanel;
	//-----> horizontal resourcesPanel
	
};

