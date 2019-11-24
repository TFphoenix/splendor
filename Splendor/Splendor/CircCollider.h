#pragma once
#include "Collider.h"

class CircCollider :public Collider
{
public:
	CircCollider(const sf::CircleShape& bodyShape);
	CircCollider(const sf::Vector2f& position, float radius);
	CircCollider(sf::Vector2f&& position, float radius);

	bool DetectMouseCollision(sf::Vector2i&& mousePosition) override;

	//TEST
	void OnMouseEnter() override;
	void OnMouseLeave() override;

private:
	sf::CircleShape m_body;
};

