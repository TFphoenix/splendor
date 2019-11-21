#include "Collider.h"

void Collider::HandleEvent(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
		if (DetectMouseCollision(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
		{
			OnMouseOver();
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (DetectMouseCollision(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				OnMouseLeftClick();
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				OnMouseRightClick();
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (DetectMouseCollision(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				OnMouseLeftRelease();
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				OnMouseRightRelease();
			}
		}
		break;
	default:
		break;
	}
}