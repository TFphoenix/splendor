#pragma once
#include "UIInfoPanel.h"

#include <SFML/Graphics.hpp>

class Collider;

class UIGameSession :public sf::Drawable
{
public:
	enum class Events
	{
		// possible events hapening in the scene
		None,
		MenuButton
	};

public:
	UIGameSession(const sf::Vector2u& windowSize);
	~UIGameSession();

	// UI Logic
	void StartGame();
	void StopGame();
	void UpdateGame();
	void NextTurn();
	
	// Events
	void PassEvent(const sf::Event& event);
	Events GetEvent() const;

	// Graphics
	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
	std::vector<UIPanel*> m_panels;
	UIInfoPanel m_infoPanel;
	// m_playersPanel
	// m_tokensPanel
	// m_noblesPanel
	// m_expansionsPanel
	// m_handPanel
	// m_handPanelBackground

};

