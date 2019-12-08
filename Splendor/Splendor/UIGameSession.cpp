#include "UIGameSession.h"

UIGameSession::UIGameSession(const sf::Vector2u& windowSize) :
	// instantiate UI panels
	m_infoPanel(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, windowSize.y * 0.05))
{
	// instantiate UI components

	// Populate panel vector
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_infoPanel));
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
	// evaluate states
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
}
