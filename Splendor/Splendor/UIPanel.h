#pragma once
#include "Collider.h"

#include <SFML/Graphics.hpp>
#include <vector>

class UIPanel :public sf::RectangleShape
{
public:
	// Constr.
	UIPanel(const std::string& title, const sf::Vector2f& size = sf::Vector2f(0, 0), bool isActive = true);

	// G&S
	std::string GetTitle() const;
	void SetTitle(const std::string& title);
	bool IsActive() const;
	void SetActive(bool active);

	// Content
	Collider* GetContentCollider(size_t contentID) const;
	sf::Drawable* GetContentDrawable(size_t contentID) const;
	size_t ContentSize()const;

protected:
	// Content
	void AddContent(std::pair<Collider*, sf::Drawable*> contentItem);

private:
	std::string m_titleString;
	bool m_isActive;
	std::vector<std::pair<Collider*, sf::Drawable*>> m_content;
};

