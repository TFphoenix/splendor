#pragma once
#include "Collider.h"

class RectCollider :Collider
{
public:
	RectCollider(const sf::Rect<int>& body);
	RectCollider(const sf::RectangleShape& bodyShape);
	RectCollider(const sf::Vector2i& position, const sf::Vector2i& size);
	RectCollider(sf::Vector2i&& position, sf::Vector2i&& size);

	bool DetectMouseCollision(sf::Vector2i&& mousePosition) override;

private:
	sf::Rect<int> m_body;
};

