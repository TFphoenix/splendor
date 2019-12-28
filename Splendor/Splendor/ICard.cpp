#include "ICard.h"

ICard::ICard(uint16_t id, bool isFaceUp) :
	m_id(id),
	m_isFaceUp(isFaceUp) {}

ICard::~ICard() = default;

void ICard::SetPrestigePoints(uint16_t prestigePoints)
{
	m_prestigePoints = prestigePoints;
}

uint16_t ICard::GetId() const
{
	return m_id;
}

bool ICard::GetIsFaceUp() const
{
	return m_isFaceUp;
}

void ICard::SetIsFaceUp(bool isFaceUp)
{
	m_isFaceUp = isFaceUp;
}

uint16_t ICard::GetPrestigePoints()
{
	return m_prestigePoints;
}
