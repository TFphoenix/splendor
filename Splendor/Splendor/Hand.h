#pragma once
#include<vector>
#include"ExpansionCard.h"
#include"Token.h"
#include"optional"
class Hand
{
public:
	Hand(std::vector<std::optional<ExpansionCard>> expansionCard, std::vector<std::optional<Token>> token);
	void AddToken(std::vector<std::optional<Token>>token);
	void AddExpansionCard(std::optional<ExpansionCard > card);
	int	GetSizeOfToken();
	int	GetSizeOfExpansionCard();
	void RemoveToken();
	
private:
	std::vector<std::optional<Token>> m_token;
	std::vector<std::optional<ExpansionCard>> m_expansionCard;
};

