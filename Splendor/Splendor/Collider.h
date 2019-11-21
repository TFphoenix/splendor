#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider() = default;

	void HandleEvent(const sf::Event& event);

	virtual bool DetectMouseCollision(sf::Vector2i&& mousePosition) = 0;

protected:
	virtual void OnMouseOver();
	virtual void OnMouseLeftClick();
	virtual void OnMouseRightClick();
	virtual void OnMouseLeftRelease();
	virtual void OnMouseRightRelease();
};

