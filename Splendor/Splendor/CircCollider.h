#pragma once
#include "Collider.h"

class CircCollider :Collider
{
public:
	//CircCollider(const sf::Rect<int>& body);
	CircCollider(const sf::CircleShape& bodyShape);
	//CircCollider(const sf::Vector2i& position, const sf::Vector2i& size);
	//CircCollider(sf::Vector2i&& position, sf::Vector2i&& size);

	bool DetectMouseCollision(sf::Vector2i&& mousePosition) override;

private:
	//sf::Rect<int> m_body;
};

