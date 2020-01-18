#include "UILeaderboardSession.h"

UILeaderboardSession::UILeaderboardSession(const sf::Vector2u& windowSize) :
	m_gameModePanel("First place", UIOptionsPanel::Type::Radio,
		sf::Vector2f(50.0f, 0.2f * windowSize.y + 30.0f),
		sf::Vector2f(windowSize.x - 50.0f, 0.15f * windowSize.y))
{
	// Title Background
	m_titleBackground.setPosition(0, 0);
	m_titleBackground.setSize(sf::Vector2f(windowSize.x, 0.2f * windowSize.y));
	m_titleBackground.setFillColor(UIColors::DarkYellow);

	// Title
	m_title.setString("LeaderBoard");
	m_title.setCharacterSize(80);
	m_title.setFillColor(UIColors::NeutralWhite);
	m_title.setPosition(windowSize.x / 2.0f, 0.2f * windowSize.y / 2.0f);
	m_title.AlignText(UIText::TextAlign::mid_center);

	//Button
	sf::RectangleShape button({ 300,80 });

	// Main Menu Button
	button.setPosition(windowSize.x - 350.0f, windowSize.y - 130.0f);
	m_backToMenuButton = new UIButton(button);
	m_backToMenuButton->ChangeText("Main Menu");
}

UILeaderboardSession::~UILeaderboardSession()
{
	delete m_backToMenuButton;
}

void UILeaderboardSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_titleBackground);
	target.draw(m_title);
	target.draw(m_gameModePanel);
	target.draw(*m_backToMenuButton);

}

void UILeaderboardSession::PassEvent(const sf::Event& event)
{
	m_backToMenuButton->HandleEvent(event);
	
}

UILeaderboardSession::Events UILeaderboardSession::GetEvent() const
{
	if (m_backToMenuButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}
	return Events::None;
}
