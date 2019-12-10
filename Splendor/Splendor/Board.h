#include "ExpansionCard.h"
#include"Token.h"
#include"NobleCard.h"
#include "TokenPile.h"
#include "Deck.h"
#include "CardDAO.h"
#include <vector>
#include <cstdint>
#include<array>
#pragma once

class Board
{
public:
	Board(std::array <Deck<ExpansionCard>, 3 > cards,
		std::array<TokenPile, 6>tokens,
		std::array<std::optional<CardDAO::Data>, 5> nobles, 
		std::array<std::optional<CardDAO::Data>, 4> expansionL3,
		std::array<std::optional<CardDAO::Data>, 4> expansionL2,
		std::array<std::optional<CardDAO::Data>, 4> expansionL1);
	void TakeExpansion();
	NobleCard WinNoble();
	void RecieveTokens(std::vector<std::pair<IToken::Type,uint16_t>> tokens);
	
	
private:
	std::array <Deck<ExpansionCard>, 3 > m_cards;
	std::array<TokenPile, 6>m_tokens;
	std::array<std::optional<CardDAO::Data>, 5> m_nobles;
	std::array<std::optional<CardDAO::Data>, 4> m_expansionL3;
	std::array<std::optional<CardDAO::Data>, 4> m_expansionL2;
	std::array<std::optional<CardDAO::Data>, 4> m_expansionL1;
};

