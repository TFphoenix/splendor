#include "ExpansionCard.h"
#include "CardDAO.h"

ExpansionCard::ExpansionCard(Level level, uint16_t id, bool isFaceUp) :
	ICard(id, isFaceUp),
	m_level(level)
{
	// Select card from database
	CardDAO::Expansion card;
	switch (level)
	{
	case Level::Level1:
		card = CardDAO::GetL1Expansion(id);
		break;
	case Level::Level2:
		card = CardDAO::GetL2Expansion(id);
		break;
	case Level::Level3:
		card = CardDAO::GetL3Expansion(id);
		break;
	default:
		CardDAO::GetL1Expansion(0);
		break;
	}

	// Set-up object's properties
	m_rewardType = card.reward;
	m_prestigePoints = card.prestige;
	m_cost = card.request;
}

ExpansionCard::Level ExpansionCard::GetLevel() const
{
	return m_level;
}

ICard::GemType ExpansionCard::GetRewardType() const
{
	return m_rewardType;
}

ICard::GemsMap ExpansionCard::GetCost() const
{
	return m_cost;
}
