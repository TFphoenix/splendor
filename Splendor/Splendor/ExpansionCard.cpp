#include "ExpansionCard.h"

ExpansionCard::ExpansionCard(Level level,
	IToken::Type rewardType,
	uint16_t gEcost,
	uint16_t bScost,
	uint16_t wDcost,
	uint16_t bOcost,
	uint16_t rRcost,
	uint16_t prestigePoints,
	bool isFaceUp) :
	ICard(prestigePoints, isFaceUp),
	m_level(level),
	m_rewardType(rewardType)
{
	m_cost[IToken::Type::GreenEmerald] = gEcost;
	m_cost[IToken::Type::BlueSapphire] = bScost;
	m_cost[IToken::Type::WhiteDiamond] = wDcost;
	m_cost[IToken::Type::blackOnyx] = bOcost;
	m_cost[IToken::Type::RedRuby] = rRcost;
}
