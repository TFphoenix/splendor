#pragma once
#include <array>
#include <unordered_map>
#include <optional>

#include "ExpansionCard.h"
#include "NobleCard.h"
#include "CardDAO.h"


class Hand
{
public:
	using GemType = IToken::Type;
	using GemsMap = std::unordered_map<GemType, uint16_t>;

public:
	// Constr.
	Hand() = default;

	// Getters
	std::vector<CardDAO::Data> GetExpansionsData() const;
	std::vector<CardDAO::Data> GetNoblesData() const;
	GemsMap& GetResourcesData() const;
	GemsMap& GetTokensData() const;

	// Manipulators
	void AddResource(GemType type);
	void AddToken(GemType type, uint16_t amount = 1);
	void RemoveToken(GemType type, uint16_t amount);
	void AddExpansionCard(const ExpansionCard& card);
	void RemoveExpansionCard(uint16_t id);
	void AddNobleCard(const NobleCard& card);

private:
	mutable GemsMap m_resources;
	mutable GemsMap m_tokens;
	std::array<std::optional<ExpansionCard>, 3> m_expansionCards;
	std::array<std::optional<NobleCard>, 5> m_nobleCards;
};

