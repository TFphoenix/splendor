#pragma once
#include <vector>

#include <SFML/Graphics.hpp>
#include <map>
#include<stack>
class Entity
{
private:

protected:

	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt,const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
		
};

