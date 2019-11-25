#include "UISelector.h"

UISelector::UISelector(const std::string& title, const sf::Vector2f& position, const sf::Vector2f& size, bool initialState) :
	Rect<float>(position, size),
	m_title(UIText(position, UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisBold, title, size.y * 0.2f)),
	m_isChecked(initialState)
{
	m_title.setPosition(position.x + size.x / 2.0f, (position.y + 0.3f * size.y / 2.0f));
	m_title.AlignText(UIText::TextAlign::mid_center);
}
