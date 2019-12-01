#include "TokenPile.h"

void TokenPile::ShuffleDeck()
{

	Randomizer::Shuffle(t_token);
}

Token TokenPile::DrawToken()
{
	Token topCard = t_token.front();
	t_token.pop_back();
	return topCard;
}

