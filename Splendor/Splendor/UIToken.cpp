#include "UIToken.h"

std::vector<sf::Texture> UIToken::s_tokenTextures;

UIToken::UIToken(IToken::Type tokenType, const sf::Vector2f& position, float radius) :CircCollider(position, radius), CircleShape(radius)
{
	setOrigin(radius, radius);
	setPosition(position);
	if (s_tokenTextures.empty())
	{
		LoadTextures();
	}
	setTexture(&s_tokenTextures[static_cast<int>(tokenType)]);
}

void UIToken::LoadTextures()
{
	s_tokenTextures.resize(s_texturesCount);
	size_t textureIndex = 0;
	for (auto& texture : s_tokenTextures)
	{
		switch (static_cast<IToken::Type>(textureIndex++))
		{
		case IToken::Type::GreenEmerald:
			texture.loadFromFile(s_texturesFile + "greenEmerald.png");
			break;
		case IToken::Type::BlueSapphire:
			texture.loadFromFile(s_texturesFile + "blueSaphire.png");
			break;
		case IToken::Type::WhiteDiamond:
			texture.loadFromFile(s_texturesFile + "whiteDiamond.png");
			break;
		case IToken::Type::BlackOnyx:
			texture.loadFromFile(s_texturesFile + "blackOnyx.png");
			break;
		case IToken::Type::RedRuby:
			texture.loadFromFile(s_texturesFile + "redRuby.png");
			break;
		case IToken::Type::Gold:
			texture.loadFromFile(s_texturesFile + "gold.png");
			break;
		default:
			texture.loadFromFile(s_texturesFile + "greenEmerald.png");
			break;
		}
	}
}
