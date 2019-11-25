#pragma once
#include "RectCollider.h"
#include "UISelector.h"
#include "UIColors.h"

class UICheckBox :public UISelector, public RectCollider, public sf::Drawable
{
public:
	struct Design
	{
		sf::Color fillColor;
		sf::Color outlineColor;
	};

public:
	UICheckBox(const std::string& title, const sf::Vector2f& position = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(100, 100), const Design& uncheckedDesign = Design{ UIColors::DarkBlue,UIColors::GoldYellow }, const Design& checkedDesign = Design{ UIColors::GoldYellow,sf::Color(255,255,255) });

	void ChangeState() override;
	void OnMouseLeftClick() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
	void UpdateDesign();

private:
	sf::RectangleShape m_box;
	Design m_uncheckedDesign, m_checkedDesign;
	Design* m_currentDesign;
};

