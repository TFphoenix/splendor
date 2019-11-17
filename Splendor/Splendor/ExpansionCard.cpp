#include "ExpansionCard.h"
#include <fstream>
#include <iostream>
ExpansionCard::ExpansionCard(Level level,
	IToken::Type rewardType,
	uint16_t gECost,
	uint16_t bSCost,
	uint16_t wDCost,
	uint16_t bOCost,
	uint16_t rRCost,
	uint16_t prestigePoints,
	bool isFaceUp) :
	ICard(prestigePoints, isFaceUp),
	m_level(level),
	m_rewardType(rewardType)
{
	m_cost[IToken::Type::GreenEmerald] = gECost;
	m_cost[IToken::Type::BlueSapphire] = bSCost;
	m_cost[IToken::Type::WhiteDiamond] = wDCost;
	m_cost[IToken::Type::BlackOnyx] = bOCost;
	m_cost[IToken::Type::RedRuby] = rRCost;
}

void ExpansionCard::ReadCards(const ExpansionCard& card)
{
	uint16_t green, blue, white, black, red;

	switch (card.m_level)
	{
	case Level::Level1:
	{ 
		std::ifstream fileName("Level1.txt");
		switch (card.m_rewardType)
		{
		case IToken::Type::GreenEmerald:
		{
			for (int index = 0; index < 8; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level1, IToken::Type::GreenEmerald, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlueSapphire:
		{
			for (int index = 0; index < 8; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level1, IToken::Type::BlueSapphire, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::WhiteDiamond:
		{
			for (int index = 0; index < 8; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level1, IToken::Type::WhiteDiamond, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlackOnyx:
		{
			for (int index = 0; index < 8; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level1, IToken::Type::BlackOnyx, green, blue, white, black, red));
			}
			break;

		}
		case IToken::Type::RedRuby:
		{
			for (int index = 0; index < 8; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level1, IToken::Type::RedRuby, green, blue, white, black, red));
			}
			break;
		}


		default:
		{
			throw "Invalid  type";
		}
		}

	}
	case Level::Level2:
	{
		std::ifstream fileName("Level2.txt");
		switch (card.m_rewardType)
		{
		case IToken::Type::GreenEmerald:
		{
			for (int index = 0; index < 6; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level2, IToken::Type::GreenEmerald, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlueSapphire:
		{
			for (int index = 0; index < 6; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level2, IToken::Type::BlueSapphire, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::WhiteDiamond:
		{
			for (int index = 0; index < 6; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level2, IToken::Type::WhiteDiamond, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlackOnyx:
		{
			for (int index = 0; index < 6; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level2, IToken::Type::BlackOnyx, green, blue, white, black, red));
			}
			break;

		}
		case IToken::Type::RedRuby:
		{
			for (int index = 0; index < 6; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level2, IToken::Type::RedRuby, green, blue, white, black, red));
			}
			break;
		}


		default:
		{
			throw "Invalid  type";
		}
		}

	}
	case Level::Level3:
	{
		std::ifstream fileName("Level3.txt");
		switch (card.m_rewardType)
		{
		case IToken::Type::GreenEmerald:
		{
			for (int index = 0; index < 4; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level3, IToken::Type::GreenEmerald, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlueSapphire:
		{
			for (int index = 0; index < 4; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level3, IToken::Type::BlueSapphire, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::WhiteDiamond:
		{
			for (int index = 0; index < 4; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level3, IToken::Type::WhiteDiamond, green, blue, white, black, red));
			}
			break;
		}
		case IToken::Type::BlackOnyx:
		{
			for (int index = 0; index < 4; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level3, IToken::Type::BlackOnyx, green, blue, white, black, red));
			}
			break;

		}
		case IToken::Type::RedRuby:
		{
			for (int index = 0; index < 4; index++)
			{
				fileName >> green >> blue >> white >> black >> red;
				m_cards.push_back(ExpansionCard(Level::Level3, IToken::Type::RedRuby, green, blue, white, black, red));
			}
			break;
		}

		default:
		{
			throw "Invalid  type";
		}
		}

	}
	default:
	{
		throw "Invalid level type";
	}

	}


}
