#pragma once
#include <SFML/Graphics.hpp>

// Pregame & Panels
#include "PregameSetup.h"
#include "UIInfoPanel.h"
#include "UIPlayersPanel.h"
#include "UIVTokensPanel.h"
#include "UICardsRowPanel.h"
#include "UIHandPanel.h"

// Logic
#include "Board.h"

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
	UIGameSession(const sf::Vector2u& windowSize, const PregameSetup& pregameSetup);

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
	// Pregame & Panels
	PregameSetup m_pregameSetup;
	std::vector<UIPanel*> m_panels;
	UIInfoPanel m_infoPanel;
	UIPlayersPanel m_playersPanel;
	UIVTokensPanel m_tokensPanel;
	UICardsRowPanel m_noblesPanel;
	UICardsRowPanel m_expansionsL1Panel;
	UICardsRowPanel m_expansionsL2Panel;
	UICardsRowPanel m_expansionsL3Panel;
	UIHandPanel m_handPanel;

	// UI Logic
	bool m_openedHandPanel;

	// Logic
	/*Board* p_Board;
	std::vector<Player*> p_Players;*/

};

