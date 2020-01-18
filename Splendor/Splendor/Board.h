#pragma once
#include "Deck.h"
#include "CardDAO.h"

#include <cstdint>
#include <array>
#include <optional>

class NetworkPacket;

class Board
{
public:
	Board();

	// Logic
	void ReplaceExpansion(ExpansionCard::Level level, uint16_t id);
	ExpansionCard DrawExpansionFromDeck(uint16_t deck);
	NobleCard WinNoble(uint16_t id);
	void TakeToken(IToken::Type type, uint16_t amount = 1);
	void ReturnToken(IToken::Type type, uint16_t amount = 1);
	void ReturnTokens(std::unordered_map<IToken::Type, uint16_t>&& tokens);

	// Getters
	std::vector<CardDAO::Data> GetCardSlotsData(CardDAO::Type dataType) const;
	std::unordered_map<IToken::Type, uint16_t> GetTokensData() const;
	bool IsExpansionDeckEmpty(uint16_t deckLevel);
	Deck<NobleCard> GetNobleDeck() const;

	// Networking
	std::tuple < std::string, std::string, std::string, std::string, std::string > ConvertBoardToPackage() const;
	void ConvertPackageToBoard(NetworkPacket& networkPacket);
	std::tuple < std::string, std::string, std::string, std::string> ConvertDecksToPackage() const;

private:
	// Networking
	template <class T, size_t size>
	void TokenizePackage(std::array<std::optional<T>, size>& toSlots, std::string&& fromString)
	{
		for (auto& slot : toSlots)
		{
			slot.reset();
		}
		size_t position = 0;
		size_t iterator = 0;
		while ((position = fromString.find(NetworkPacket::s_delimiter)) != std::string::npos)
		{
			const auto& token = fromString.substr(0, position);
			toSlots[iterator].emplace(std::stoi(token));
			fromString.erase(0, position + NetworkPacket::s_delimiter.length());
			++iterator;
		}
	}

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

