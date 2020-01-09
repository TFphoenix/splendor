#include "Board.h"

Board::Board() :
	m_nobleDeck()
{
	// Shuffle Decks
	m_nobleDeck.ShuffleDeck();
	m_expansionL3Deck.ShuffleDeck();
	m_expansionL2Deck.ShuffleDeck();
	m_expansionL1Deck.ShuffleDeck();

	// Populate Card Slots
	for (uint16_t slot = 0; slot < GamePieces::GetNobleCardCount(); ++slot)
	{
		m_nobleSlots[slot] = m_nobleDeck.DrawCard();
	}
	for (auto& slot : m_expansionL3Slots)
	{
		slot = m_expansionL3Deck.DrawCard();
	}
	for (auto& slot : m_expansionL2Slots)
	{
		slot = m_expansionL2Deck.DrawCard();
	}
	for (auto& slot : m_expansionL1Slots)
	{
		slot = m_expansionL1Deck.DrawCard();
	}

	// Populate Token Slots
	m_tokens[IToken::Type::Gold] = GamePieces::s_GoldTokenCount;
	for (uint16_t tokenIt = 0; tokenIt < IToken::s_typeCount - 1; ++tokenIt)
	{
		m_tokens[static_cast<IToken::Type>(tokenIt)] = GamePieces::GetGemTokenCount();
	}
}

ExpansionCard Board::TakeExpansion(ExpansionCard::Level level, uint16_t id)
{
	std::optional<ExpansionCard> cardToReturn;
	switch (level)
	{
	case ExpansionCard::Level::Level1:
		for (auto& card : m_expansionL1Slots)
		{
			if (card.has_value())
			{
				if (card->GetId() == id)
				{
					card.swap(cardToReturn);
				}
			}
		}
		break;
	case ExpansionCard::Level::Level2:
		for (auto& card : m_expansionL2Slots)
		{
			if (card.has_value())
			{
				if (card->GetId() == id)
				{
					card.swap(cardToReturn);
				}
			}
		}
		break;
	case ExpansionCard::Level::Level3:
		for (auto& card : m_expansionL3Slots)
		{
			if (card.has_value())
			{
				if (card->GetId() == id)
				{
					card.swap(cardToReturn);
				}
			}
		}
		break;
	default:
		throw std::invalid_argument("Can't take expansion of undefined level");
	}
	if (!cardToReturn.has_value())
		throw std::invalid_argument("Card not found");
	return cardToReturn.value();
}

NobleCard Board::WinNoble(uint16_t id)
{
	std::optional<NobleCard> cardToReturn;
	for (auto& card : m_nobleSlots)
	{
		if (card.has_value())
		{
			if (card->GetId() == id)
			{
				card.swap(cardToReturn);
			}
		}
	}
	if (!cardToReturn.has_value())
		throw std::invalid_argument("Card not found");
	return cardToReturn.value();
}

void Board::TakeToken(IToken::Type type, uint16_t amount)
{
	if (amount > m_tokens[type])
		throw std::out_of_range("Insufficient tokens");
	m_tokens[type] -= amount;
}

void Board::ReturnToken(IToken::Type type, uint16_t amount)
{
	if (type == IToken::Type::Gold)
	{
		if (amount + m_tokens[type] > GamePieces::s_GoldTokenCount)
			throw std::out_of_range("Returned token amount out of range");
	}
	else
	{
		if (amount + m_tokens[type] > GamePieces::GetGemTokenCount())
			throw std::out_of_range("Returned token amount out of range");
	}

	m_tokens[type] += amount;
}

std::vector<CardDAO::Data> Board::GetCardSlotsData(CardDAO::Type dataType) const
{
	std::vector<CardDAO::Data> dataToReturn;
	switch (dataType)
	{
	case CardDAO::Type::Noble:
		for (const auto& slot : m_nobleSlots)
		{
			if (slot.has_value())
			{
				dataToReturn.emplace_back(dataType, slot->GetId());
			}
		}
		break;
	case CardDAO::Type::ExpansionL1:
		for (const auto& slot : m_expansionL1Slots)
		{
			if (slot.has_value())
			{
				dataToReturn.emplace_back(dataType, slot->GetId());
			}
		}
		break;
	case CardDAO::Type::ExpansionL2:
		for (const auto& slot : m_expansionL2Slots)
		{
			if (slot.has_value())
			{
				dataToReturn.emplace_back(dataType, slot->GetId());
			}
		}
		break;
	case CardDAO::Type::ExpansionL3:
		for (const auto& slot : m_expansionL3Slots)
		{
			if (slot.has_value())
			{
				dataToReturn.emplace_back(dataType, slot->GetId());
			}
		}
		break;
	default:
		throw std::invalid_argument("Can't get card slots data of UNKNOWN type");;
	}
	return dataToReturn;
}

std::unordered_map<IToken::Type, uint16_t> Board::GetTokensData() const
{
	return m_tokens;
}
