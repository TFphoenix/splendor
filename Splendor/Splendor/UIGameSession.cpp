#include "UIGameSession.h"
#include "UISelectedCard.h"

UIGameSession::UIGameSession(const sf::Vector2u& windowSize, const PregameSetup& pregameSetup, std::vector<Player>* pPlayers, Board* pBoard) :
	// instantiate Logic
	p_board(pBoard),
	// instantiate UI panels
	m_infoPanel(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, windowSize.y * 0.05)),
	m_playersPanel(pPlayers, sf::Vector2f(0, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.95)),
	m_tokensPanel(sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.05), sf::Vector2f(0.1 * windowSize.x, windowSize.y * 0.95)),
	m_noblesPanel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.26)),
	m_expansionsL3Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.31), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL2Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.54), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL1Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.77), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_handPanel(static_cast<sf::Vector2f>(windowSize), false),
	m_openedHandPanel(false),
	// instantiate Pregame Set-up
	m_pregameSetup(pregameSetup)
{
	// Instantiate UI Card Rows
	m_noblesPanel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::Noble), 0, true);
	m_noblesPanel.ReverseDrawOrder();
	m_expansionsL3Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL3), 3);
	m_expansionsL3Panel.ReverseDrawOrder();
	m_expansionsL2Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL2), 2);
	m_expansionsL2Panel.ReverseDrawOrder();
	m_expansionsL1Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL1), 1);
	m_expansionsL1Panel.ReverseDrawOrder();

	// Populate panel vector
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_infoPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_playersPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_tokensPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL1Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL2Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL3Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_noblesPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_handPanel));
}

void UIGameSession::StartGame()
{
	m_infoPanel.StartTimer();
}

void UIGameSession::StopGame()
{
	m_infoPanel.StopTimer();
}

void UIGameSession::UpdateGame()
{
	// Info
	m_infoPanel.UpdateTime();

	// Board
	m_tokensPanel.UpdateTokens();

	// Hand Panel
	const auto triggeredPanel = m_playersPanel.GetIfTriggered();
	if (triggeredPanel != nullptr)
	{
		m_handPanel.SetUpHand(*triggeredPanel);
		m_handPanel.SetActive(true);
	}
	m_handPanel.CheckForClose();
}

void UIGameSession::NextTurn()
{
	m_infoPanel.IncrementTurn();
}

void UIGameSession::PassEvent(const sf::Event& event)
{
	// iterate panel vector and handle events
	std::for_each(m_panels.begin(), m_panels.end(), [&event](UIPanel* panel)
	{
		panel->HandleEvent(event);
	});
}

UIGameSession::Events UIGameSession::GetEvent() const
{
	// Info Panel
	if (m_infoPanel.MenuButtonTriggered())
		return Events::MenuButton;
	return Events::None;
}

void UIGameSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// iterate panel vector and draw panels
	std::for_each(m_panels.begin(), m_panels.end(), [&target](UIPanel* panel)
		{
			target.draw(*panel);
		});
	// re-draw selected card on top of all drawables
	if (UISelectedCard::Get() != nullptr)
	{
		target.draw(*UISelectedCard::Get());
	}
}
