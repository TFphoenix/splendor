#pragma once
#include "ICard.h"
#include  "IToken.h"

#include <map>

class ExpansionCard :ICard
{
public:
	enum class Level {
		Level1 = 1,
		Level2,
		Level3
	};

public:
	ExpansionCard(Level level,
		IToken::Type rewardType,
		uint16_t gEcost,
		uint16_t bScost,
		uint16_t wDcost,
		uint16_t bOcost,
		uint16_t rRcost,
		uint16_t prestigePoints = 0,
		bool isFaceUp = false);

private:
	Level m_level;
	IToken::Type m_rewardType;
	std::map<IToken::Type, uint16_t> m_cost;
};

