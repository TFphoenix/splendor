#pragma once
#include "UICard.h"
#include "UIText.h"
#include "UIColors.h"

class UISelectedCard
{
public:
	UISelectedCard() = delete;

	static void Set(sf::Drawable* card);
	static void UpdateText(const sf::Vector2f& position);
	static void DisplayText(bool displayText);
	static std::pair<sf::Drawable*, sf::Drawable*> Get();

private:
	inline static sf::Drawable* s_selectedCard = nullptr;
	inline static UIText s_text = UIText(sf::Vector2f(), UIText::TextAlign::classic, UIText::AvailableFonts::LatoBlack, "LEFT CLICK TO BUY\nRIGHT CLICK TO HOLD", 40, UIColors::GoldYellow, UIColors::OpaqueBlack, 3);
	inline static bool s_displayText = false;
	const inline static uint16_t s_textDistance = 20;// px
};

