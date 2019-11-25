#pragma once
#include "UIText.h"
#include "UIButton.h"
#include "UIOptionsPanel.h"
#include "UICheckBox.h"
#include "Collider.h"
#include "UIColors.h"

class UIPreGameSession :public sf::Drawable
{
public:
	UIPreGameSession(const sf::Vector2u& windowSize);
	~UIPreGameSession();

	// Events
	void PassEvent(const sf::Event& event);
	bool BackToMainMenu() const;
	bool StartGame() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
	UIText m_title;
	sf::RectangleShape m_titleBackground;
	UIOptionsPanel m_gameModePanel, m_playersPanel, m_otherSettingsPanel;
	Collider* m_startGameButton;
	Collider* m_mainMenuButton;

};

