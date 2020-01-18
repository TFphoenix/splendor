#pragma once

// UI
#include "UIText.h"
#include "UIButton.h"
#include "UIOptionsPanel.h"
#include "UISelectorBox.h"
#include "Collider.h"
#include "UIColors.h"


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

	//static inline std::vector<sf::Sprite> s_tutorialImages;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;
	void PassEvent(const sf::Event& event);
	Events GetEvent() const;


private:
	const inline static std::string s_imageFile = "../external/Resources/Textures/Tutorial/";
	static inline const uint16_t s_imagesSize = 9;
	UIText m_title;
	sf::RectangleShape m_titleBackground;
	UIOptionsPanel m_gameModePanel;
	UIButton* m_backToMenuButton;
	static inline sf::Texture* s_texture;
	static inline sf::Sprite* s_sprite;;

};

