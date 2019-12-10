#pragma once
#include "UICard.h"

class UISelectedCard
{
public:
	static void Set(sf::Drawable* card);
	static sf::Drawable* Get();

private:
	inline static sf::Drawable* s_selectedCard = nullptr;
};

