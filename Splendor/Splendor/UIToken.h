#pragma once
#include "CircCollider.h"
#include "IToken.h"

#include <SFML/Graphics.hpp>

class UIToken :public CircCollider, public sf::CircleShape
{
public:
	UIToken(IToken::Type tokenType, const sf::Vector2f& position = sf::Vector2f(0, 0), float radius = 50);

private:
	static void LoadTextures();

private:
	const inline static std::string s_texturesFile = "../external/Resources/Textures/Tokens/";
	static std::vector<sf::Texture> s_tokenTextures;
	static inline const size_t s_texturesCount = 6;
};

