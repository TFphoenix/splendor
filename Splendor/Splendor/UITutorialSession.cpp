#include "UITutorialSession.h"


UITutorialSession::UITutorialSession(const sf::Vector2u& windowSize) :
	m_gameModePanel("Tutorial: ", UIOptionsPanel::Type::Radio,
		sf::Vector2f(50.0f, 0.2f * windowSize.y + 30.0f),
		sf::Vector2f(windowSize.x - 50.0f, 0.15f * windowSize.y))
{
	// Title Background
	m_titleBackground.setPosition(0, 0);
	m_titleBackground.setSize(sf::Vector2f(windowSize.x, 0.2f * windowSize.y));
	m_titleBackground.setFillColor(UIColors::DarkYellow);


	
	//Button
	sf::RectangleShape button({ 300,80 });

	// Main Menu Button
	button.setPosition(windowSize.x - 670.0f, windowSize.y - 130.0f);
	m_backToMenuButton = new UIButton(button);
	m_backToMenuButton->ChangeText("Main Menu");
}

UITutorialSession::~UITutorialSession()
{
	delete m_nextButton;
	delete m_backToMenuButton;
	delete m_previousButton;
}

void UITutorialSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_titleBackground);
	target.draw(m_title);
	target.draw(m_gameModePanel);
	//target.draw(*m_nextButton);
	target.draw(*m_backToMenuButton);
	//target.draw(*m_previousButton);
}

void UITutorialSession::PassEvent(const sf::Event& event)
{

	m_backToMenuButton->HandleEvent(event);
}

UITutorialSession::Events UITutorialSession::GetEvent() const
{
	if (m_backToMenuButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}
	/*if (m_previousButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}
	if (m_nextButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}*/
	return Events::None;
}
