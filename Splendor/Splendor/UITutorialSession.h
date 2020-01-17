#pragma once

// UI
#include "UIText.h"
#include "UIButton.h"
#include "UIOptionsPanel.h"
#include "UISelectorBox.h"
#include "Collider.h"
#include "UIColors.h"


class UITutorialSession : public sf::Drawable
{

public:
	enum class Events
	{
		None,
		MainMenu
		//StartGame
	};

public:
	UITutorialSession(const sf::Vector2u& windowSize);
	~UITutorialSession();

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

	void PassEvent(const sf::Event& event);
	Events GetEvent() const;

private:
	UIText m_title;
	sf::RectangleShape m_titleBackground;
	UIOptionsPanel m_gameModePanel;
	UIButton* m_nextButton;
	UIButton* m_previousButton;
	UIButton* m_backToMenuButton;
};

