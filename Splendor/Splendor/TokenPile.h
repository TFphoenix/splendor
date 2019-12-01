#pragma once
#include "Randomizer.h"
#include<vector>
#include"Token.h"
class TokenPile
{
public:
	void ShuffleDeck();
	Token DrawToken();
private:
	std::vector<Token> t_token;

};

