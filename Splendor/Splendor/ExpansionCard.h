#pragma once
#include "ICard.h"
#include  "IToken.h"

#include <map>
#include <vector>

class ExpansionCard :ICard
{
public:
	enum class Level {
		Level1 = 1,
		Level2,
		Level3
	};

public:
	ExpansionCard(
		Level level,
		IToken::Type rewardType,
		uint16_t gECost,
		uint16_t bSCost,
		uint16_t wDCost,
		uint16_t bOCost,
		uint16_t rRCost,
		uint16_t prestigePoints = 0,
		bool isFaceUp = false);

	//void ReadCards(const ExpansionCard& card);

private:
	Level m_level : 1;
	IToken::Type m_rewardType;
	std::map<IToken::Type, uint16_t> m_cost;
	std::vector<ExpansionCard> m_cards;

};

