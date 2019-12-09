#include "UICardsRowPanel.h"

UICardsRowPanel::UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position, const sf::Vector2f& size,
	bool isActive) :
	UIPanel("CardsRow", size, position, isActive),
	m_cards(cardSlots, nullptr)
{
	// calculate content box
	const sf::Vector2f contentPosition(position.x + s_xPaddingPercentage * size.x, position.y + s_yPaddingPercentage * size.y);
	const sf::Vector2f contentSize(size.x - 2 * s_xPaddingPercentage * size.x, size.y - 2 * s_yPaddingPercentage * size.y);

	// calculate distance between cards
	const float distance = contentSize.x / static_cast<float>(cardSlots);

	// calculate card size based on Y and card texture ratio
	const float cardSizeY = size.y - 2 * s_yPaddingPercentage * size.y;
	const float cardSizeX = cardSizeY * 238.0f / 357.0f;
	const sf::Vector2f cardSize(cardSizeX, cardSizeY);

	uint16_t it = 0;
	while (it < cardSlots)
	{
		// create card data & UI
		m_cardsData.emplace_back(CardDAO::Type::Unknown, 0);
		m_cards[it] = new UICard(2, UICard::Type::Noble, sf::Vector2f(position.x + s_xPaddingPercentage * size.x + static_cast<float>(it)* distance, position.y + s_yPaddingPercentage * size.y), cardSize);

		// add card Collider and Drawable to panel
		AddContent(dynamic_cast<Collider*>(m_cards[it]));
		AddContent(dynamic_cast<sf::Drawable*>(m_cards[it]));

		// increment iterator
		++it;
	}
}

std::vector<CardData> UICardsRowPanel::GetCardsData() const
{
	return m_cardsData;
}

void UICardsRowPanel::SetCardsData(const std::vector<CardData>& cardsData)
{
	m_cardsData = cardsData;
}
