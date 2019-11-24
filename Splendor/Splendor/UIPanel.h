#pragma once
#include "Collider.h"

#include <SFML/Graphics.hpp>
#include <vector>

class UIPanel :public sf::RectangleShape
{
public:
	// Constr.
	UIPanel(std::string&& name, sf::Vector2f size = sf::Vector2f(0, 0), bool isActive = true);

	// G&S
	std::string GetName() const;
	void SetName(const std::string& name);
	bool IsActive() const;
	void SetActive(bool active);

	// Content
	void AddContent(Collider* contentItem);

private:
	std::string m_name;
	bool m_isActive;
	std::vector<Collider*> m_content;
};

