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

void Board::ReplaceExpansion(ExpansionCard::Level level, uint16_t id)
{
	switch (level)
	{
	case ExpansionCard::Level::Level1:
		for (auto& card : m_expansionL1Slots)
		{
			if (card.has_value())
			{
				if (card->GetId() == id)
				{
					try {
						card.emplace(m_expansionL1Deck.DrawCard());
					}
					catch (std::out_of_range & exception)
					{
						card.reset();
					}
					return;
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
					try {
						card.emplace(m_expansionL2Deck.DrawCard());
					}
					catch (std::out_of_range & exception)
					{
						card.reset();
					}
					return;
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
					try {
						card.emplace(m_expansionL3Deck.DrawCard());
					}
					catch (std::out_of_range & exception)
					{
						card.reset();
					}
					return;
				}
			}
		}
		break;
	default:
		throw std::invalid_argument("Can't take expansion of undefined level");
	}
	throw std::invalid_argument("Card not found");
}

ExpansionCard Board::DrawExpansionFromDeck(uint16_t deck)
{
	switch (deck)
	{
	case 1:
		return m_expansionL1Deck.DrawCard();
	case 2:
		return m_expansionL2Deck.DrawCard();
	case 3:
		return m_expansionL3Deck.DrawCard();
	default:
		throw std::invalid_argument("Undefined deck<" + std::to_string(deck) + ">");
	}
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
	return std::move(cardToReturn.value());
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

void Board::ReturnTokens(std::unordered_map<IToken::Type, uint16_t>&& tokens)
{
	for (uint16_t gemTypeIterator = 0; gemTypeIterator < IToken::s_typeCount; ++gemTypeIterator)
	{
		const auto gemType = static_cast<IToken::Type>(gemTypeIterator);
		m_tokens[gemType] += tokens[gemType];
	}
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

bool Board::IsExpansionDeckEmpty(uint16_t deckLevel)
{
	switch (deckLevel)
	{
	case 1:
		return m_expansionL1Deck.IsEmpty();
	case 2:
		return m_expansionL2Deck.IsEmpty();
	case 3:
		return m_expansionL3Deck.IsEmpty();
	default:
		throw std::invalid_argument("Invalid expansion deck level");
	}
}
