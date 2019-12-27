#include "UIHandPanel.h"
#include "UIColors.h"

UIHandPanel::UIHandPanel(const sf::Vector2f& size, bool isActive) :
	UIPanel("UIHandPanel", size),
	m_cover(size),
	m_outerBackground(sf::Vector2f(size.x* s_sizeRatio, size.y* s_sizeRatio)),
	m_innerBackground(sf::Vector2f(size.x* s_sizeRatio - 2 * s_lowPadding, size.y* s_sizeRatio - s_highPadding * size.y * s_sizeRatio - s_lowPadding)),
	m_panelBackgrounds({
		sf::RectangleShape(sf::Vector2f(m_innerBackground.getSize().x - 2 * s_lowPadding - (1 - s_firstRowRatio) * m_innerBackground.getSize().x,m_innerBackground.getSize().y - s_lowPadding - (1 - s_columnRatio) * m_innerBackground.getSize().y)),
		sf::RectangleShape(sf::Vector2f(m_innerBackground.getSize().x - s_lowPadding - s_firstRowRatio * m_innerBackground.getSize().x,m_innerBackground.getSize().y - s_lowPadding - (1 - s_columnRatio) * m_innerBackground.getSize().y)),
		sf::RectangleShape(sf::Vector2f(m_innerBackground.getSize().x - 2 * s_lowPadding - (1 - s_secondRowRatio) * m_innerBackground.getSize().x,m_innerBackground.getSize().y - 2 * s_lowPadding - s_columnRatio * m_innerBackground.getSize().y)),
		sf::RectangleShape(sf::Vector2f(m_innerBackground.getSize().x - s_lowPadding - s_secondRowRatio * m_innerBackground.getSize().x,m_innerBackground.getSize().y - 2 * s_lowPadding - s_columnRatio * m_innerBackground.getSize().y))
		})
{
	// Cover
	m_cover.setPosition(sf::Vector2f());
	m_cover.setFillColor(UIColors::DarkGray - UIColors::QuarterTransparent);

	// Outer Background
	m_outerBackground.setOrigin(m_outerBackground.getSize().x / 2, m_outerBackground.getSize().y / 2);
	m_outerBackground.setPosition(size.x / 2, size.y / 2);
	m_outerBackground.setFillColor(UIColors::GoldYellow);

	// Inner Background
	m_innerBackground.setOrigin(m_innerBackground.getSize().x / 2, m_innerBackground.getSize().y);
	m_innerBackground.setPosition(size.x / 2, size.y / 2 + m_outerBackground.getSize().y / 2 - s_lowPadding);
	m_innerBackground.setFillColor(UIColors::DarkBlue);

	// Panel Backgrounds
	for (auto& panel : m_panelBackgrounds)
	{
		panel.setFillColor(UIColors::NavyBlue);
	}
	const auto leftTopCorner = sf::Vector2f(m_innerBackground.getPosition().x - m_innerBackground.getSize().x / 2, m_innerBackground.getPosition().y - m_innerBackground.getSize().y);
	m_panelBackgrounds[0].setPosition(leftTopCorner.x + s_lowPadding, leftTopCorner.y + s_lowPadding);
	m_panelBackgrounds[1].setPosition(leftTopCorner.x + 2 * s_lowPadding + m_panelBackgrounds[0].getSize().x, leftTopCorner.y + s_lowPadding);
	m_panelBackgrounds[2].setPosition(leftTopCorner.x + s_lowPadding, leftTopCorner.y + 2 * s_lowPadding + m_panelBackgrounds[0].getSize().y);
	m_panelBackgrounds[3].setPosition(leftTopCorner.x + 2 * s_lowPadding + m_panelBackgrounds[2].getSize().x, leftTopCorner.y + 2 * s_lowPadding + m_panelBackgrounds[0].getSize().y);

	// Panels
	m_expansionsPanel = new UICardsRowPanel(3, m_panelBackgrounds[0].getPosition(), m_panelBackgrounds[0].getSize(), sf::Vector2f(0.025f, 0.075f));
	m_noblesPanel = new UICardsRowPanel(5, m_panelBackgrounds[1].getPosition(), m_panelBackgrounds[1].getSize(), sf::Vector2f(0.025f, 0.075f));
	m_resourcesPanel = new UIHResourcesPanel(m_panelBackgrounds[2].getPosition(), m_panelBackgrounds[2].getSize());
	m_tokensPanel = new UIHTokensPanel(m_panelBackgrounds[3].getPosition(), m_panelBackgrounds[3].getSize());



	// Dummy Data
	const std::vector<UICard::Data> nobles({
		UICard::Data(UICard::Type::Noble,3,true),
		UICard::Data(UICard::Type::Noble,1,true),
		UICard::Data(UICard::Type::Noble,6,true),
		UICard::Data(UICard::Type::Noble,8,true),
		UICard::Data(UICard::Type::Noble,10,true)
		});
	const std::vector<UICard::Data> expansions({
		UICard::Data(UICard::Type::ExpansionL3,6),
		UICard::Data(UICard::Type::ExpansionL3,8),
		UICard::Data(UICard::Type::ExpansionL3,20)
		});
	m_noblesPanel->SetCardsData(nobles);
	m_expansionsPanel->SetCardsData(expansions);



	// Close Button
	sf::RectangleShape buttonShape;
	UIButton::Design buttonNoneDesign(
		{
			UIColors::DarkBlue,
			UIColors::NeutralWhite,
			3.0f
		},
		{
			"",
			UIText::AvailableFonts::DosisLight,
			30,
			UIColors::NeutralWhite,
			UIColors::NeutralWhite,
			1.5f
		});
	const float buttonSize = (m_outerBackground.getSize().y - m_innerBackground.getSize().y - 3 * s_lowPadding) / 2.0f;
	buttonShape.setSize(sf::Vector2f(buttonSize, buttonSize));
	buttonShape.setPosition(m_outerBackground.getPosition().x + m_outerBackground.getSize().x / 2.0f - buttonSize - s_lowPadding - 3.0f,
		m_outerBackground.getPosition().y - m_outerBackground.getSize().y / 2.0f + s_lowPadding + 3.0f);
	m_closeButton = new UIButton(buttonShape, buttonNoneDesign);
	m_closeButton->ChangeText("x");

	// Add content to UIPanel
	AddContent(dynamic_cast<sf::Drawable*>(&m_cover));
	AddContent(dynamic_cast<sf::Drawable*>(&m_outerBackground));
	AddContent(dynamic_cast<sf::Drawable*>(&m_innerBackground));
	for (auto& panel : m_panelBackgrounds)
	{
		AddContent(dynamic_cast<sf::Drawable*>(&panel));
	}
	AddContent(dynamic_cast<sf::Drawable*>(m_expansionsPanel));
	AddContent(dynamic_cast<sf::Drawable*>(m_noblesPanel));
	AddContent(dynamic_cast<sf::Drawable*>(m_resourcesPanel));
	AddContent(dynamic_cast<sf::Drawable*>(m_tokensPanel));
	AddContent(dynamic_cast<sf::Drawable*>(m_closeButton));
	AddContent(dynamic_cast<Collider*>(m_closeButton));

}
