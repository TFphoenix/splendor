#include "UIInfoPanel.h"
#include "UIColors.h"

UIInfoPanel::UIInfoPanel(const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("InfoPanel", size, isActive),
	m_timeTitle(sf::Vector2f(position.x + s_padding, position.y + s_padding), UIText::TextAlign::classic, UIText::AvailableFonts::DosisBold, "Time: "),
	m_timeLabel(sf::Vector2f(m_timeTitle.getPosition().x + m_timeTitle.getGlobalBounds().width + s_padding, position.y + s_padding), UIText::TextAlign::classic, UIText::AvailableFonts::DosisLight, "00:00:00"),
	m_turnTitle(sf::Vector2f(position.x + m_timeLabel.getGlobalBounds().width + 300, position.y + s_padding), UIText::TextAlign::classic, UIText::AvailableFonts::DosisBold, "Turn: "),
	m_turnLabel(sf::Vector2f(m_turnTitle.getPosition().x + m_turnTitle.getGlobalBounds().width + s_padding, position.y + s_padding), UIText::TextAlign::classic, UIText::AvailableFonts::DosisLight, "0"),
	m_timerRunning(false),
	m_turn(0)
{
	// Re-scale UIText
	const auto scale = (size.y - s_padding) / (m_timeTitle.getGlobalBounds().top + m_timeTitle.getGlobalBounds().height);
	m_timeTitle.setScale(scale, scale);
	m_timeLabel.setScale(scale, scale);
	m_turnTitle.setScale(scale, scale);
	m_turnLabel.setScale(scale, scale);

	// Menu Button
	sf::RectangleShape buttonShape(sf::Vector2f(0.05 * size.x, size.y - 2 * s_padding));
	buttonShape.setPosition(position.x + size.x - buttonShape.getSize().x - s_padding, position.y + s_padding);
	m_menuButton = new UIButton(buttonShape);
	m_menuButton->ChangeText("x");// future texture

	//Background
	sf::RectangleShape* background = new sf::RectangleShape(size);
	background->setPosition(position);
	background->setFillColor(UIColors::DarkBlue);

	// Add content to panel
	AddContent(dynamic_cast<Drawable*>(background));
	AddContent(dynamic_cast<sf::Drawable*>(&m_timeTitle));
	AddContent(dynamic_cast<sf::Drawable*>(&m_timeLabel));
	AddContent(dynamic_cast<sf::Drawable*>(&m_turnTitle));
	AddContent(dynamic_cast<sf::Drawable*>(&m_turnLabel));
	AddContent(dynamic_cast<sf::Drawable*>(m_menuButton));
	AddContent(dynamic_cast<Collider*>(m_menuButton));
}

void UIInfoPanel::IncrementTurn()
{
	m_turn++;
}

void UIInfoPanel::UpdateTime()
{
	if (m_timerRunning)
	{
		m_currentTime = std::chrono::system_clock::now();
		UpdateTimeLabel();
	}
}

void UIInfoPanel::StartTimer()
{
	m_timerRunning = true;
	m_startTime = std::chrono::system_clock::now();
}

void UIInfoPanel::StopTimer()
{
	m_timerRunning = false;
}

bool UIInfoPanel::MenuButtonTriggered() const
{
	return m_menuButton->GetState() == UIButton::State::Release;
}

void UIInfoPanel::UpdateTimeLabel()
{
	//calculate elapsed time and convert it into string
}
