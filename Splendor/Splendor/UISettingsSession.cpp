#include "UISettingsSession.h"

UISettingsSession::UISettingsSession(const sf::Vector2u& windowSize) :
	// Game Mode Panel
	m_gameModePanel("Music: ", UIOptionsPanel::Type::Radio,
		sf::Vector2f(50.0f, 0.2f * windowSize.y + 30.0f),
		sf::Vector2f(windowSize.x - 50.0f, 0.15f * windowSize.y))
{
	// Title Background
	m_titleBackground.setPosition(0, 0);
	m_titleBackground.setSize(sf::Vector2f(windowSize.x, 0.2f * windowSize.y));
	m_titleBackground.setFillColor(UIColors::DarkYellow);

	// Title
	m_title.setString("Settings");
	m_title.setCharacterSize(80);
	m_title.setFillColor(UIColors::NeutralWhite);
	m_title.setPosition(windowSize.x / 2.0f, 0.2f * windowSize.y / 2.0f);
	m_title.AlignText(UIText::TextAlign::mid_center);





	//Button
	sf::RectangleShape button({ 300,80 });

	// Main Menu Button
	button.setPosition(windowSize.x - 670.0f, windowSize.y - 130.0f);
	m_mainMenuButton = new UIButton(button);
	m_mainMenuButton->ChangeText("Main Menu");
}

UISettingsSession::~UISettingsSession()
{
	delete m_mainMenuButton;
}

void UISettingsSession::PassEvent(const sf::Event& event)
{
	m_gameModePanel.HandleEvent(event);
	m_mainMenuButton->HandleEvent(event);
}

UISettingsSession::Events UISettingsSession::GetEvent() const
{

	if (m_mainMenuButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}
	return Events::None;
}

void UISettingsSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_titleBackground);
	target.draw(m_title);
	target.draw(m_gameModePanel);
	target.draw(*m_mainMenuButton);
}
