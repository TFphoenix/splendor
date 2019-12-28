#include "Hand.h"

void Hand::AddResource(GemType type)
{
	++m_resources[type];
}

void Hand::AddToken(GemType type, uint16_t amount)
{
	m_tokens[type] += amount;
}

void Hand::RemoveToken(GemType type, uint16_t amount)
{
	if (m_tokens[type] < amount)
		throw std::out_of_range("Amount of tokens to be removed out of range");
	m_tokens[type] -= amount;
}

void Hand::AddExpansionCard(const ExpansionCard& card)
{
	for (auto& expansionCard : m_expansionCards)
	{
		if (!expansionCard.has_value())
		{
			expansionCard = card;
			return;
		}
	}
	throw std::out_of_range("Hand is full, can't add expansion card");
}

void Hand::RemoveExpansionCard(uint16_t id)
{
	for (auto& card : m_expansionCards)
	{
		if (card.has_value())
		{
			if (card.value().GetId() == id)
			{
				card.reset();
				return;
			}
		}
	}
	throw std::invalid_argument("Expansion card with given id not found");
}

void Hand::AddNobleCard(const NobleCard& card)
{
	for (auto& nobleCard : m_nobleCards)
	{
		if (!nobleCard.has_value())
		{
			nobleCard = card;
			return;
		}
	}
	throw std::out_of_range("Hand is full, can't add noble card");
}
