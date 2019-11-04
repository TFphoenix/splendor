#include "ICard.h"

ICard::ICard(uint16_t prestigePoints, bool isFaceUp) :
	m_prestigePoints(prestigePoints),
	m_isFaceUp(isFaceUp) {}

ICard::~ICard() = default;
