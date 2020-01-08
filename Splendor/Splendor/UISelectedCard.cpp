#include "UISelectedCard.h"

void UISelectedCard::Set(sf::Drawable* card)
{
	s_selectedCard = card;
}

void UISelectedCard::UpdateText(const sf::Vector2f& position)
{
	const auto textBounds = s_text.getLocalBounds();
	s_text.setPosition(position - sf::Vector2f(textBounds.width + s_textDistance, 0));
}

void UISelectedCard::DisplayText(bool displayText)
{
	s_displayText = displayText;
}

std::pair<sf::Drawable*, sf::Drawable*> UISelectedCard::Get()
{
	return std::make_pair(s_selectedCard, dynamic_cast<sf::Drawable*>(s_displayText ? &s_text : nullptr));
}
