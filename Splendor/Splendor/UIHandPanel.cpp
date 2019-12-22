#include "UIHandPanel.h"
#include "UIColors.h"

UIHandPanel::UIHandPanel(const sf::Vector2f& size, bool isActive) :
	UIPanel("UIHandPanel", size),
	m_cover(size),
	m_outerBackground(sf::Vector2f(size.x* s_sizeRatio, size.y* s_sizeRatio)),
	m_innerBackground(sf::Vector2f(size.x - 2 * s_lowPadding * size.x, size.y - (s_lowPadding + s_highPadding) * size.y)),
	m_panelBackgrounds({
		sf::RectangleShape(sf::Vector2f()),
		sf::RectangleShape(sf::Vector2f()),
		sf::RectangleShape(sf::Vector2f()),
		sf::RectangleShape(sf::Vector2f())
		}),
	m_expansionsPanel(3),
	m_noblesPanel(5),
	m_tokensPanel(),
	m_resourcesPanel()
{
	// Cover
	m_cover.setPosition(sf::Vector2f());
	m_cover.setFillColor(UIColors::DarkGray - UIColors::HalfTransparent);

	// Outer Background
	m_outerBackground.setPosition(sf::Vector2f(size.x - s_sizeRatio * size.x, size.y - s_sizeRatio * size.y));
	m_outerBackground.setFillColor(UIColors::GoldYellow);

	// Inner Background
	m_innerBackground.setPosition(sf::Vector2f(size.x - s_sizeRatio * size.x + s_lowPadding * size.x, size.y - s_sizeRatio * size.y + (1 - s_highPadding) * size.y));
	m_innerBackground.setFillColor(UIColors::DarkBlue);

	// Sub-Panels

	// Close Button

	// Add content to UIPanel
	AddContent(dynamic_cast<sf::Drawable*>(&m_cover));
	AddContent(dynamic_cast<sf::Drawable*>(&m_outerBackground));
	AddContent(dynamic_cast<sf::Drawable*>(&m_innerBackground));
}
