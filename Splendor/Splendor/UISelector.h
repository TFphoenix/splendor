#pragma once
#include "UIText.h"

#include <SFML/Graphics.hpp>

class UISelector : sf::Rect<float>
{
public:
	UISelector(const std::string& title, const sf::Vector2f& position = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(100, 100), bool initialState = false);

	virtual void ChangeState() = 0;
	bool IsChecked() const;

protected:
	UIText m_title;
	bool m_isChecked;

};

