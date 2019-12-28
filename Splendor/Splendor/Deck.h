#pragma once
#include "Randomizer.h"
#include "ExpansionCard.h"
#include "NobleCard.h"
#include "GamePieces.h"

#include <string>
#include <vector>

template <class cardType, size_t level = NULL>
class Deck
{
public:
	Deck()
	{
		if (level > 3)
			throw std::invalid_argument(std::string("Failed to initialize deck of type <ExpansionCard, " + std::to_string(level) + ">"));
	}

	// Logic
	void ShuffleDeck()
	{
		Randomizer rnd;
		rnd.Shuffle(m_cards);
	}
	cardType DrawCard()
	{
		cardType topCard = m_cards.front();
		m_cards.pop_back();
		return topCard;
	}
	void AddCard(cardType&& card)
	{
		m_cards.push_back(std::move(card));
	}

private:
	std::vector<cardType> m_cards;

};
