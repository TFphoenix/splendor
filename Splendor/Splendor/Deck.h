#pragma once
//#include "ExpansionCard.h"
//#include "NobleCard.h"
#include "Randomizer.h"

#include <vector>

template <class cardType>
class Deck
{
public:
	void ShuffleDeck();
	cardType DrawCard();
	void AddCard(cardType&& card);

private:
	std::vector<cardType> m_cards;

};

template <class cardType>
void Deck<cardType>::ShuffleDeck()
{
	Randomizer rnd;
	rnd.Shuffle(m_cards);
}

template <class cardType>
cardType Deck<cardType>::DrawCard()
{
	cardType topCard = m_cards.front();
	m_cards.pop_back();
	return topCard;
}

template <class cardType>
void Deck<cardType>::AddCard(cardType&& card)
{
	m_cards.push_back(std::move(card));
}
