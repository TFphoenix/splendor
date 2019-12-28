#include "NobleCard.h"
#include "CardDAO.h"

NobleCard::NobleCard(uint16_t id, bool isFaceUp) :
	ICard(id, isFaceUp)
{
	const CardDAO::Noble card = CardDAO::GetNoble(id);
	m_prestigePoints = card.prestige;
	m_requirements = card.request;
	m_name = card.name;
}

ICard::GemsMap NobleCard::GetRequirements() const
{
	return m_requirements;
}

std::string NobleCard::GetName() const
{
	return m_name;
}

