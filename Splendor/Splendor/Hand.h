#pragma once
#include<vector>
#include"ExpansionCard.h"
#include"IToken.h"
#include"optional"
class Hand
{
public:
	Hand(std::vector<std::optional<ExpansionCard>> expansionCard, std::vector<std::optional<IToken>> token);
	void AddToken(std::vector<std::optional<IToken>>token);
	void AddExpansionCard(std::optional<ExpansionCard > card);
	int	GetSizeOfToken();
	int	GetSizeOfExpansionCard();
	void RemoveToken();
	
private:
	std::vector<std::optional<IToken>> m_token;
	std::vector<std::optional<ExpansionCard>> m_expansionCard;
};

