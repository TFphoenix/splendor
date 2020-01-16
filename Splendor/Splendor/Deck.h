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
	Deck();
	/*{
		if (level > 3)
			throw std::invalid_argument(std::string("Failed to initialize deck of type <ExpansionCard, " + std::to_string(level) + ">"));
	}*/

	// Logic
	void ShuffleDeck()
	{
		Randomizer rnd;
		rnd.Shuffle(m_cards);
	}

	cardType DrawCard()
	{
		if (m_cards.empty())
			throw std::out_of_range("Can't draw card from empty deck");
		cardType topCard = m_cards.back();
		m_cards.pop_back();
		return topCard;
	}

	void AddCard(cardType&& card)
	{
		m_cards.push_back(std::move(card));
	}

	bool IsEmpty()
	{
		return m_cards.empty();
	}

	//Getters for unit testing
	size_t GetNumberOfCards() const
	{
		return m_cards.size();
	}

private:
	std::vector<cardType> m_cards;

};
