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
	static inline const int s_top5 = 5;
	static inline 	UIText* s_playerName;
	static inline 	UIText* s_playerWins;

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;
	void PassEvent(const sf::Event& event);
	Events GetEvent() const;

	static void LoadFromFile();
	static void LoadLeaderboard(const sf::Vector2u& windowSize);



private:
	const inline static std::string s_leaderboardFile = "../external/Resources/test1.txt";
	//static inline int count = 1;
	UIText m_title;
	sf::RectangleShape m_titleBackground;
	UIOptionsPanel m_gameModePanel;
	UIButton* m_backToMenuButton;
	std::vector<sf::Drawable*> m_labelTextDrawableVector;
	static inline std::vector<sf::Drawable*> m_playerNameDrawableVector;
	static inline std::vector<sf::Drawable*> m_playerNumberOfWinsDrawableVector;
	UIText* m_labelText1;
	UIText* m_labelText2;
	UIText* m_labelText3;
	UIText* m_labelText4;
	UIText* m_labelText5;
	UIText* m_nameText;
	UIText* m_numberOfWins;


};

