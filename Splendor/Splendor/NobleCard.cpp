#include "NobleCard.h"
#include<iostream>
#include<vector>

NobleCard::NobleCard(
	uint16_t gERequirement,
	uint16_t bSRequirement,
	uint16_t wDRequirement,
	uint16_t bORequirement,
	uint16_t rRRequirement,
	uint16_t prestigePoints,
	bool isFaceUp) :
	ICard(prestigePoints, isFaceUp)
{
	m_expansionRequirements[IToken::Type::GreenEmerald] = gERequirement;
	m_expansionRequirements[IToken::Type::BlueSapphire] = bSRequirement;
	m_expansionRequirements[IToken::Type::WhiteDiamond] = wDRequirement;
	m_expansionRequirements[IToken::Type::BlackOnyx] = bORequirement;
	m_expansionRequirements[IToken::Type::RedRuby] = rRRequirement;
}

