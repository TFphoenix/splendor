#pragma once
#include "ICard.h"
#include "IToken.h"

#include <map>

class NobleCard :ICard
{
public:
	NobleCard(
		uint16_t gERequirement,
		uint16_t bSRequirement,
		uint16_t wDRequirement,
		uint16_t bORequirement,
		uint16_t rRRequirement,
		uint16_t prestigePoints = 0,
		bool isFaceUp = false);

private:
	std::map<IToken::Type, uint16_t> m_expansionRequirements;
};

