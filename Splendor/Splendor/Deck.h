#pragma once
#include "ExpansionCard.h"
#include "NobleCard.h"

#include <vector>

template <class cardType>
class Deck
{
public:
	void ShuffleDeck();
	cardType DrawCard();

private:
	std::vector<cardType> m_cards;

};

template <class cardType>
void Deck<cardType>::ShuffleDeck()
{
}

template <class cardType>
cardType Deck<cardType>::DrawCard()
{
}
