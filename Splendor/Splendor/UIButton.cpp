#include "UIButton.h"

UIButton::UIButton(const sf::RectangleShape& body) : RectCollider(body), m_body(body) {}

UIButton::UIButton(const sf::RectangleShape& body, const Design& none, const Design& hover, const Design& press, State initialState) : RectCollider(body),
m_body(body),
m_noneDesign(none),
m_hoverDesign(hover),
m_pressDesign(press),
m_currentState(initialState)
{
	// empty
}

UIButton::State UIButton::GetState() const
{
	return m_currentState;
}

void UIButton::SetState(State newState)
{
	m_currentState = newState;
}

UIButton::Design UIButton::GetDesign() const
{
	return m_currentDesign;
}

void UIButton::SetDesign(const Design& newDesign)
{
	m_currentDesign = newDesign;
}

void UIButton::OnMouseEnter()
{
	m_currentState = State::Hover;
	m_currentDesign = m_hoverDesign;
}

void UIButton::OnMouseLeave()
{
	m_currentState = State::None;
	m_currentDesign = m_noneDesign;
}

void UIButton::OnMouseLeftClick()
{
	m_currentState = State::Press;
	m_currentDesign = m_pressDesign;
}

void UIButton::OnMouseLeftRelease()
{
	m_currentState = State::None;
	m_currentDesign = m_noneDesign;
}

void UIButton::UpdateDesign()
{
	m_body.setFillColor(m_currentDesign.fillColor);
	//m_body.setOutlineColor(m_currentDesign.outlineColor);
}

void UIButton::Draw(sf::RenderWindow* window)
{
	UpdateDesign();
	window->draw(m_body);
}
