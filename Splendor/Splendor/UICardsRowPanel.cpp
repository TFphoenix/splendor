#include "UICardsRowPanel.h"

UICardsRowPanel::UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position, const sf::Vector2f& size,
	bool isActive) :
	UIPanel("CardsRow", size, position, isActive),
	m_cards(cardSlots, nullptr),
	m_cardSlots(cardSlots)
{
	// calculate content box
	const sf::Vector2f contentPosition(position.x + s_xPaddingPercentage * size.x, position.y + s_yPaddingPercentage * size.y);
	const sf::Vector2f contentSize(size.x - 2 * s_xPaddingPercentage * size.x, size.y - 2 * s_yPaddingPercentage * size.y);

	// calculate distance between cards
	m_cardDistance = contentSize.x / static_cast<float>(cardSlots);

	// calculate card size based on Y and card texture ratio
	const float cardSizeY = size.y - 2 * s_yPaddingPercentage * size.y;
	const float cardSizeX = cardSizeY * 238.0f / 357.0f;
	m_cardSize = sf::Vector2f(cardSizeX, cardSizeY);

	uint16_t it = 0;
	while (it < cardSlots)
	{
		// create empty card data & UI
		m_cards[it] = new UICard(0, UICard::Type::Unknown, sf::Vector2f(position.x + s_xPaddingPercentage * size.x + static_cast<float>(it)* m_cardDistance, position.y + s_yPaddingPercentage * size.y), m_cardSize);

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
		card->SetData(cardsData[it]);
		++it;
	}
}

void UICardsRowPanel::ReverseDrawOrder()
{
	std::reverse(m_drawableContent.begin(), m_drawableContent.end());
}
