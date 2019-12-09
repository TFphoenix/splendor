#pragma once
#include "UIPanel.h"
#include "UICard.h"
#include "CardDAO.h"

class UICardsRowPanel :public UIPanel
{
public:
	UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	// Logic
	std::vector<CardData> GetCardsData() const;
	void SetCardsData(const std::vector<CardData>& cardsData);

private:
	static inline const float s_yPaddingPercentage = 0.05f;
	static inline const float s_xPaddingPercentage = 0.1f;

private:
	std::vector<UICard*> m_cards;
	std::vector<CardData> m_cardsData;
	std::optional<CardData> m_pickedCard;

};

