#pragma once
#include "UIPanel.h"
#include "UICard.h"

#include <optional>

class UICardsRowPanel :public UIPanel
{
public:
	UICardsRowPanel(uint16_t cardSlots, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, const sf::Vector2f& padding = { 0.1f,0.05f }, bool isActive = true);

	// Logic
	std::vector<UICard::Data> GetCardsData() const;
	void SetCardsData(const std::vector<UICard::Data>& cardsData);

	// Graphics
	void ReverseDrawOrder();

private:
	uint16_t m_cardSlots;
	sf::Vector2f m_cardSize;
	float m_cardDistance;
	std::vector<UICard*> m_cards;
	std::optional<UICard::Data> m_pickedCard;

};

