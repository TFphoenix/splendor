#pragma once
#include "UIPanel.h"
#include "UIText.h"
#include "UICheckBox.h"

class UIOptionsPanel :public UIPanel
{
public:
	enum class Type
	{
		Check,
		Radio
	};

public:
	// Constr.
	UIOptionsPanel(const std::string& title, Type type, sf::Vector2f position = { 0,0 }, sf::Vector2f size = { 500,150 }, bool isActive = true);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Options Manipulators
	void AddOption(const std::string& optionName);

	//Auxiliary Handle Event Method
	void HandleEvent(const sf::Event& event);

private:
	void UpdateOptions();

private:
	UIText m_title;
	Type m_type;
	std::pair<Collider*, sf::Drawable*> m_lastOption;
	size_t m_lastCheckedID;
};

