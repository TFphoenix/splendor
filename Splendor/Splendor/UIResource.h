#pragma once
#include <SFML/Graphics.hpp>

#include "IToken.h"

class UIResource :public sf::Drawable
{
public:
	// Constr.
	UIResource(IToken::Type tokenType, const sf::Vector2f& position = sf::Vector2f(0, 0), float radius = 50);

	// G&S
	IToken::Type GetType() const;

	// Graphics
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::CircleShape GetBody();

	// Manipulators
	void SetPosition(float x, float y);
	void SetOrigin(float x, float y);
	void SetRadius(float radius);

private:
	static void LoadTextures();
	
private:
	// Textures
	const inline static std::string s_texturesFile = "../external/Resources/Textures/Resources/";
	static std::array<sf::Texture, 5> s_resourceTextures;
	
private:
	IToken::Type m_type;
	float m_radius;
	sf::CircleShape m_body;
};

