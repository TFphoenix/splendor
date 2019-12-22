#pragma once
#include <array>

#include "UIPanel.h"
#include "UIButton.h"
#include "UICardsRowPanel.h"
#include "UIHTokensPanel.h"
#include "UIHResourcesPanel.h"

class UIHandPanel :public UIPanel
{
public:
	UIHandPanel(const sf::Vector2f& size = { 1280,720 }, bool isActive = true);

	//-----> SetUpHand(Player* playerPanel, ...)

private:
	static inline float s_sizeRatio = 0.7f;
	static inline float s_lowPadding = 0.05f;
	static inline float s_highPadding = 0.8f;

private:
	// Backgrounds
	sf::RectangleShape m_cover;
	sf::RectangleShape m_outerBackground;
	sf::RectangleShape m_innerBackground;
	std::array<sf::RectangleShape, 4> m_panelBackgrounds;

	// GUI
	UIButton* m_closeButton;
	UICardsRowPanel m_expansionsPanel;
	UICardsRowPanel m_noblesPanel;
	UIHTokensPanel m_tokensPanel;
	UIHResourcesPanel m_resourcesPanel;

};

