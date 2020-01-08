#pragma once
#include <optional>

#include "UIPanel.h"
#include "UIPlayerPanel.h"

class Player;

class UIPlayersPanel :public UIPanel
{
public:
	UIPlayersPanel(std::vector<Player>* pPlayers, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	// UI Logic
	UIPlayerPanel* GetIfTriggered();
	void pointToNextPlayer();

private:
	static inline const float s_paddingPercentage = 0.04f;
	static inline const float s_panelPercentage = 0.2f;
	const static inline std::string s_playerPointerFile = "../external/Resources/Textures/UI/pointer.png";
	const static inline float s_playerPointerPadding = 0.2f;//%

private:
	std::array<std::optional<UIPlayerPanel>, 4> m_playerPanels;
	sf::RectangleShape m_playerPointer;
	std::vector<float> m_playerPointerPositions;
	size_t m_playerPointerIterator;
	size_t m_playerPointerSize;

};

