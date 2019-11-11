#include "ExpansionCard.h"

ExpansionCard::ExpansionCard(Level level,
	IToken::Type rewardType,
	uint16_t gECost,
	uint16_t bSCost,
	uint16_t wDCost,
	uint16_t bOCost,
	uint16_t rRCost,
	uint16_t prestigePoints,
	bool isFaceUp) :
	ICard(prestigePoints, isFaceUp),
	m_level(level),
	m_rewardType(rewardType)
{
	m_cost[IToken::Type::GreenEmerald] = gECost;
	m_cost[IToken::Type::BlueSapphire] = bSCost;
	m_cost[IToken::Type::WhiteDiamond] = wDCost;
	m_cost[IToken::Type::BlackOnyx] = bOCost;
	m_cost[IToken::Type::RedRuby] = rRCost;
}
