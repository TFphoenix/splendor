#pragma once
#include "UIPanel.h"
#include "UICard.h"

class UICardsRowPanel :public UIPanel
{
public:
	UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	// Logic
	std::vector<UICard::Data> GetCardsData() const;
	void SetCardsData(const std::vector<UICard::Data>& cardsData);

	// Graphics
	void ReverseDrawOrder();

private:
	// UI Responsiveness
	static inline const float s_yPaddingPercentage = 0.05f;
	static inline const float s_xPaddingPercentage = 0.1f;

private:
	uint16_t m_cardSlots;
	sf::Vector2f m_cardSize;
	float m_cardDistance;
	std::vector<UICard*> m_cards;
	std::optional<UICard::Data> m_pickedCard;

};
