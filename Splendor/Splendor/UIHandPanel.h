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
	static inline float s_sizeRatio = 0.75f;// %
	static inline float s_lowPadding = 10;// px
	static inline float s_highPadding = 0.25f;// %
	static inline float s_firstRowRatio = 0.6f;// %
	static inline float s_secondRowRatio = 0.5f;// %
	static inline float s_columnRatio = 0.75f;// %

private:
	// Backgrounds
	sf::RectangleShape m_cover;
	sf::RectangleShape m_outerBackground;
	sf::RectangleShape m_innerBackground;
	std::array<sf::RectangleShape, 4> m_panelBackgrounds;

	// GUI
	UIButton* m_closeButton;
	UICardsRowPanel* m_expansionsPanel;
	UICardsRowPanel* m_noblesPanel;
	UIHResourcesPanel* m_resourcesPanel;
	UIHTokensPanel* m_tokensPanel;

};

