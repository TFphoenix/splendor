#pragma once
#include "Deck.h"
#include "CardDAO.h"

#include <cstdint>
#include <array>
#include <optional>

class Board
{
public:
	Board();

	// Logic
	ExpansionCard TakeExpansion(ExpansionCard::Level level, uint16_t id);
	NobleCard WinNoble(uint16_t id);
	void TakeToken(IToken::Type type, uint16_t amount = 1);
	void ReturnToken(IToken::Type type, uint16_t amount = 1);

	// Getters
	std::vector<CardDAO::Data> GetCardSlotsData(CardDAO::Type dataType) const;
	std::unordered_map<IToken::Type, uint16_t> GetTokensData() const;

private:
	// Decks
	Deck<NobleCard> m_nobleDeck;
	Deck<ExpansionCard, 3> m_expansionL3Deck;
	Deck<ExpansionCard, 2> m_expansionL2Deck;
	Deck<ExpansionCard, 1> m_expansionL1Deck;

	// Board
	std::unordered_map<IToken::Type, uint16_t> m_tokens;
	std::array<std::optional<NobleCard>, 5> m_nobleSlots;
	std::array<std::optional<ExpansionCard>, 4> m_expansionL3Slots;
	std::array<std::optional<ExpansionCard>, 4> m_expansionL2Slots;
	std::array<std::optional<ExpansionCard>, 4> m_expansionL1Slots;
};

