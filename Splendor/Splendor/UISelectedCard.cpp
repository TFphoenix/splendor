#include "UISelectedCard.h"

void UISelectedCard::Set(sf::Drawable* card)
{
	s_selectedCard = card;
}

sf::Drawable* UISelectedCard::Get()
{
	return s_selectedCard;
}
