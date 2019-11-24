#include "UIButton.h"

UIButton::Design::Design(const Body& bodyDesign, const Text& textDesign) : m_bodyDesign(bodyDesign), m_textDesign(textDesign) {}

UIButton::Design::Design(Body&& bodyDesign, Text&& textDesign) : m_bodyDesign(bodyDesign), m_textDesign(std::move(textDesign)) {}

void UIButton::Design::SetBodyDesign(const Body& bodyDesign)
{
	m_bodyDesign = bodyDesign;
}

void UIButton::Design::SetTextDesign(const Text& textDesign)
{
	m_textDesign = textDesign;
}

const UIButton::Design UIButton::DefaultDesign::NoneDesign = UIButton::Design
{
	Design::Body
	{
	sf::Color(130, 130, 130),
	sf::Color(65, 65, 65),
	4.0f
	},
	Design::Text
	{
	"None",
	UIText::AvailableFonts::DosisLight,
	30,
	sf::Color(250,10,10),
	sf::Color(255,255,255),
	1.5f
	}
};
const UIButton::Design UIButton::DefaultDesign::HoverDesign = UIButton::Design
{
	Design::Body
	{
	sf::Color(200, 200, 200),
	sf::Color(100, 100, 100),
	4.0f
	},
	Design::Text
	{
	"Hover",
	UIText::AvailableFonts::PixellettersFull,
	30,
	sf::Color(10,255,10),
	sf::Color(255,255,255),
	3.0f
	}
};
const UIButton::Design UIButton::DefaultDesign::PressDesign = UIButton::Design
{
	Design::Body
	{
	sf::Color(60, 60, 60),
	sf::Color(30, 30, 30),
	4.0f
	},
	Design::Text
	{
	"Press",
	UIText::AvailableFonts::DosisLight,
	30,
	sf::Color(10,10,255),
	sf::Color(255,255,255),
	1.5f
	}
};

UIButton::UIButton(const sf::RectangleShape& body, const Design& none, const Design& hover, const Design& press, State initialState) : RectCollider(body),
m_body(body),
m_noneDesign(none),
m_hoverDesign(hover),
m_pressDesign(press),
m_currentState(initialState)
{
	// align UIText mid-center
	m_text.AlignText(UIText::TextAlign::mid_center);

	// position UIText mid-center
	m_text.PositionText(m_body);

	m_currentDesign = &m_noneDesign;
}

UIButton::State UIButton::GetState() const
{
	return m_currentState;
}

void UIButton::SwitchState(State newState)
{
	m_currentState = newState;
	switch (newState) {
	case State::None:
		m_currentDesign = &m_noneDesign;
		break;
	case State::Hover:
		m_currentDesign = &m_hoverDesign;
		break;
	case State::Press:
		m_currentDesign = &m_pressDesign;
		break;
	default:
		break;
	}
}

UIButton::Design UIButton::GetDesign() const
{
	return *m_currentDesign;
}

void UIButton::OnMouseEnter()
{
	m_currentState = State::Hover;
	m_currentDesign = &m_hoverDesign;
}

void UIButton::OnMouseLeave()
{
	m_currentState = State::None;
	m_currentDesign = &m_noneDesign;
}

void UIButton::OnMouseLeftClick()
{
	m_currentState = State::Press;
	m_currentDesign = &m_pressDesign;
}

void UIButton::OnMouseLeftRelease()
{
	m_currentState = State::Hover;
	m_currentDesign = &m_hoverDesign;
}

void UIButton::UpdateDesign()
{
	//Update Body
	m_body.setFillColor(m_currentDesign->m_bodyDesign.fillColor);
	m_body.setOutlineColor(m_currentDesign->m_bodyDesign.outlineColor);
	m_body.setOutlineThickness(m_currentDesign->m_bodyDesign.outlineThickness);

	//Update Text
	m_text.setString(m_currentDesign->m_textDesign.text);
	m_text.SetFont(m_currentDesign->m_textDesign.font);
	m_text.AlignText(UIText::TextAlign::mid_center);
	m_text.setCharacterSize(m_currentDesign->m_textDesign.fontSize);
	m_text.setFillColor(m_currentDesign->m_textDesign.fontFill);
	m_text.setOutlineColor(m_currentDesign->m_textDesign.fontOutline);
	m_text.setOutlineThickness(m_currentDesign->m_textDesign.outlineThickness);
}

void UIButton::Draw(sf::RenderWindow* window)
{
	UpdateDesign();
	window->draw(m_body);
	window->draw(m_text);
}
