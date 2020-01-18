#pragma once

// UI
#include "UIText.h"
#include "UIButton.h"
#include "UIOptionsPanel.h"
#include "UISelectorBox.h"
#include "Collider.h"
#include "UIColors.h"

#include <algorithm>
#include <fstream>

class UILeaderboardSession :public sf::Drawable
{

public:
	enum class Events
	{
		None,
		MainMenu
	};


public:
	UILeaderboardSession(const sf::Vector2u& windowSize);
	~UILeaderboardSession();

	static inline std::vector<std::pair<std::string, uint16_t>> s_leaderboard;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;
	void PassEvent(const sf::Event& event);
	Events GetEvent() const;

	static void LoadFromFile();



private:
	const inline static std::string s_leaderboardFile = "../external/Resources/test1.txt";
	//static inline int count = 1;
	UIText m_title;
	sf::RectangleShape m_titleBackground;
	UIOptionsPanel m_gameModePanel;
	UIButton* m_backToMenuButton;
	UIText* m_labelText;


};

