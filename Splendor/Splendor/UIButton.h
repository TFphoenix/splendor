#pragma once
#include "RectCollider.h"

#include <SFML/Graphics.hpp>

class UIButton :public RectCollider
{
public:
	enum class State
	{
		None,
		Hover,
		Press
	};
	struct Design
	{
		//Design() = default;
		//Design(const sf::Color fillC) :fillColor(fillC) {}

		sf::Color fillColor;
		sf::Color outlineColor;
		//sf::Color fontColor;
	};

public:
	// Constr.
	UIButton(const sf::RectangleShape& body);
	UIButton(const sf::RectangleShape& body, const Design& none, const Design& hover, const Design& press, State initialState = State::None);

	// G&S
	State GetState() const;
	void SetState(State newState);
	Design GetDesign() const;
	void SetDesign(const Design& newDesign);

	// Events
	void OnMouseEnter() override;
	void OnMouseLeave() override;
	void OnMouseLeftClick() override;
	void OnMouseLeftRelease() override;

	// Graffix
	void Draw(sf::RenderWindow* window);

private:
	void UpdateDesign();

private:
	// Aspect
	sf::RectangleShape m_body;
	Design m_noneDesign, m_hoverDesign, m_pressDesign;
	Design m_currentDesign;
	// Functionality
	State m_currentState;
};

