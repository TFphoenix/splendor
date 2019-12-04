#pragma once
#include <SFML/Graphics.hpp>

class Collider;

class UIGameSession :public sf::Drawable
{
public:
	enum class Events
	{
		// possible events hapening in the scene
	};

public:
	UIGameSession(const sf::Vector2u& windowSize);
	~UIGameSession();

	// Events
	void PassEvent(const sf::Event& event);
	Events GetEvent() const;

	// Graphics
	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
	std::vector<sf::Drawable*> m_drawableVector;
	std::vector<Collider*> m_colliderVector;

};

