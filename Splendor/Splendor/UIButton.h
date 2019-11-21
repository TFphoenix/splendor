#pragma once
#include <SFML/Graphics.hpp>

class UIButton
{
public:
	enum class State
	{
		NONE,
		HOVER,
		CLICK,
		PRESS
	};

private:
	// Aspect
	sf::RectangleShape m_body;
	sf::Color m_noneColor, m_hoverColor, m_clickColor, m_pressColor;
	// Functionality
	State m_currentState;
};

