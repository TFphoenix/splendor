#pragma once
#include "Collider.h"

#include <SFML/Graphics.hpp>
#include <vector>

class UIPanel :public sf::RectangleShape
{
public:
	// Constr.
	UIPanel(const std::string& title, sf::Vector2f size = sf::Vector2f(0, 0), bool isActive = true);

	// G&S
	std::string GetTitle() const;
	void SetTitle(const std::string& title);
	bool IsActive() const;
	void SetActive(bool active);

	// Content
	Collider* GetContent(size_t contentID) const;
	size_t GetContentSize()const;

protected:
	// Content
	void AddContent(Collider* contentItem);

private:
	std::string m_titleString;
	bool m_isActive;
	std::vector<Collider*> m_content;
};

