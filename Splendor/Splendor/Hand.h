#pragma once
#include<vector>
#include <array>
#include <unordered_map>

#include"ExpansionCard.h"
#include"Token.h"
#include"optional"

class Hand
{
public:
	using GemType = IToken::Type;
	using GemsMap = std::unordered_map<GemType, uint16_t>;

public:
	// Constr.
	Hand(std::vector<std::optional<ExpansionCard>> expansionCard, std::vector<std::optional<Token>> token);

	// Manipulators
	void AddToken(GemType type, uint16_t amount);
	void RemoveToken(GemType type, uint16_t amount);
	void AddExpansionCard();
	void RemoveExpansionCard();

private:
	GemsMap m_resources;
	GemsMap m_tokens;
	std::array<std::optional<ExpansionCard>, 3> m_expansionCards;
};

