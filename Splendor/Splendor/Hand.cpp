#include "Hand.h"

Hand::Hand(std::vector<std::optional<ExpansionCard>> expansionCard, std::vector<std::optional<Token>> token): m_expansionCard(expansionCard),m_token(token)
{
}

void Hand::AddToken(std::vector<std::optional<Token>> token)
{
	if (m_token.size() <= 7)
		m_token = token;
	if (m_token.size() == 8 && token.size() == 2)
		m_token = token;
}

void Hand::AddExpansionCard(std::optional<ExpansionCard> card)
{
	m_expansionCard.push_back(card);
}

int Hand::GetSizeOfToken()
{
	return m_token.size();
}

int Hand::GetSizeOfExpansionCard()
{
	return m_expansionCard.size();
}
