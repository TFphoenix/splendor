#include "UIGameSession.h"
#include "UISelectedCard.h"

UIGameSession::UIGameSession(const sf::Vector2u& windowSize, const PregameSetup& pregameSetup) :
	// instantiate UI panels
	m_infoPanel(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, windowSize.y * 0.05)),
	m_playersPanel(m_pregameSetup.GetPlayerCount(), sf::Vector2f(0, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.95)),
	m_tokensPanel(sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.05), sf::Vector2f(0.1 * windowSize.x, windowSize.y * 0.95)),
	m_noblesPanel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.26)),
	m_expansionsL3Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.31), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL2Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.54), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL1Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.77), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_handPanel(static_cast<sf::Vector2f>(windowSize), false),
	m_openedHandPanel(false),
	// instantiate pregame Setup
	m_pregameSetup(pregameSetup)
{
	// instantiate UI components
	std::vector<UICard::Data> nobles({
		UICard::Data(UICard::Type::Noble,3,true),
		UICard::Data(UICard::Type::Noble,1,true),
		UICard::Data(UICard::Type::Noble,6,true),
		UICard::Data(UICard::Type::Noble,8,true),
		UICard::Data(UICard::Type::Noble,10,true)
		});
	std::vector<UICard::Data> eL3({
		UICard::Data(UICard::Type::Background,3,true),
		UICard::Data(UICard::Type::ExpansionL3,1),
		UICard::Data(UICard::Type::ExpansionL3,6),
		UICard::Data(UICard::Type::ExpansionL3,8),
		UICard::Data(UICard::Type::ExpansionL3,20)
		});
	std::vector<UICard::Data> eL2({
		UICard::Data(UICard::Type::Background,2,true),
		UICard::Data(UICard::Type::ExpansionL2,1),
		UICard::Data(UICard::Type::ExpansionL2,15),
		UICard::Data(UICard::Type::ExpansionL2,20),
		UICard::Data(UICard::Type::ExpansionL2,30)
		});
	std::vector<UICard::Data> eL1({
		UICard::Data(UICard::Type::Background,1,true),
		UICard::Data(UICard::Type::ExpansionL1,11),
		UICard::Data(UICard::Type::ExpansionL1,26),
		UICard::Data(UICard::Type::ExpansionL1,32),
		UICard::Data(UICard::Type::ExpansionL1,40)
		});
	m_noblesPanel.SetCardsData(nobles);
	m_noblesPanel.ReverseDrawOrder();
	m_expansionsL3Panel.SetCardsData(eL3);
	m_expansionsL3Panel.ReverseDrawOrder();
	m_expansionsL2Panel.SetCardsData(eL2);
	m_expansionsL2Panel.ReverseDrawOrder();
	m_expansionsL1Panel.SetCardsData(eL1);
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
	m_infoPanel.UpdateTime();
	m_tokensPanel.UpdateTokens();
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
