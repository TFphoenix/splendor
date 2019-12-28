#include "UICardsRowPanel.h"

UICardsRowPanel::UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position, const sf::Vector2f& size, const sf::Vector2f& padding, bool isActive) :
	UIPanel("CardsRow", size, position, isActive),
	m_cards(cardSlots, nullptr),
	m_cardSlots(cardSlots)
{
	// calculate card size based on Y and card texture ratio
	const float cardSizeY = size.y - 2 * padding.y * size.y;
	const float cardSizeX = cardSizeY * 238.0f / 357.0f;
	m_cardSize = sf::Vector2f(cardSizeX, cardSizeY);

	// calculate content box
	const sf::Vector2f contentPosition(position.x + padding.x * size.x, position.y + padding.y * size.y);
	const sf::Vector2f contentSize(size.x - 2 * padding.x * size.x, size.y - 2 * padding.y * size.y);

	// calculate distance between cards
	m_cardDistance = (contentSize.x - cardSizeX) / static_cast<float>(cardSlots - 1);

	uint16_t it = 0;
	while (it < cardSlots)
	{
		// create empty card data & UI
		m_cards[it] = new UICard(0, UICard::Type::Unknown, sf::Vector2f(contentPosition.x + static_cast<float>(it)* m_cardDistance, contentPosition.y), m_cardSize);

		// add card Collider and Drawable to panel
		AddContent(dynamic_cast<Collider*>(m_cards[it]));
		AddContent(dynamic_cast<sf::Drawable*>(m_cards[it]));

		// increment iterator
		++it;
	}
}

std::vector<UICard::Data> UICardsRowPanel::GetCardsData() const
{
	std::vector<UICard::Data> cardsData;
	for (const auto& card : m_cards)
	{
		cardsData.push_back(card->GetData());
	}
	return cardsData;
}

void UICardsRowPanel::SetCardsData(const std::vector<UICard::Data>& cardsData)
{
	uint16_t it = 0;
	for (const auto& card : m_cards)
	{
		if (it < cardsData.size())
			card->SetData(cardsData[it]);
		else
			card->SetData(UICard::Data());
		++it;
	}
}

void UICardsRowPanel::SetCardsData(const std::vector<CardDAO::Data>& cardsData, uint16_t withBackground, bool isDataNumb)
{
	uint16_t it = 0;

	switch (withBackground)
	{
	case 1:
		m_cards[0]->SetData(UICard::Data(UICard::Type::Background, 1, true));
		break;
	case 2:
		m_cards[0]->SetData(UICard::Data(UICard::Type::Background, 2, true));
		break;
	case 3:
		m_cards[0]->SetData(UICard::Data(UICard::Type::Background, 3, true));
		break;
	default:
		break;
	}

	for (const auto& card : m_cards)
	{
		if (!withBackground || it)
		{
			if (it < cardsData.size())
				card->SetData(UICard::Data(static_cast<UICard::Type>(static_cast<int>(cardsData[it].type)), cardsData[it].id, isDataNumb));
			else
				card->SetData(UICard::Data());
			++it;
		}
		else
		{
			withBackground = 0;
		}
	}
}

void UICardsRowPanel::ReverseDrawOrder()
{
	std::reverse(m_drawableContent.begin(), m_drawableContent.end());
}
