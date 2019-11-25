#include "UICheckBox.h"

UICheckBox::UICheckBox(const std::string& title, const sf::Vector2f& position, const sf::Vector2f& size, const Design& uncheckedDesign, const Design& checkedDesign) :
	UISelector(title, position, size, false),
	RectCollider(
		sf::Vector2i(position.x + (size.x / 2.0f - 0.15f * size.y),
			position.y + (0.6f * size.y / 2.0f + 0.15f * size.y)),
		sf::Vector2i(0.3f * size.y, 0.3f * size.y)),
	m_uncheckedDesign(uncheckedDesign),
	m_checkedDesign(checkedDesign)
{
	m_box.setPosition(m_body.left, m_body.top);
	m_box.setSize(sf::Vector2f(m_body.width, m_body.height));
	m_box.setOutlineThickness(m_box.getSize().x / 8.0f);
	m_currentDesign = &m_uncheckedDesign;
	UpdateDesign();
}

void UICheckBox::ChangeState()
{
	if (m_isChecked)
	{
		m_isChecked = false;
		m_currentDesign = &m_uncheckedDesign;
	}
	else
	{
		m_isChecked = true;
		m_currentDesign = &m_checkedDesign;
	}
	UpdateDesign();
}

void UICheckBox::OnMouseLeftClick()
{
	ChangeState();
}

void UICheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_title);
	target.draw(m_box);
}

void UICheckBox::UpdateDesign()
{
	m_box.setFillColor(m_currentDesign->fillColor);
	m_box.setOutlineColor(m_currentDesign->outlineColor);
}
