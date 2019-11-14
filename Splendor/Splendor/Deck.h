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

