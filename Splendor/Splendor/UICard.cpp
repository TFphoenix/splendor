#include "UICard.h"
#include "GamePieces.h"

UICard::UICard(const sf::Vector2f& position, const sf::Vector2f& size) :
	RectCollider(position, size),
	RectangleShape(size)
{
	setPosition(position);
	if (!s_texturesLoaded)
	{
		LoadTextures();
		s_texturesLoaded = true;
	}
	// TEST
	setTexture(s_nobleTextures[9]);
}

void UICard::LoadTextures()
{
	// Background Textures
	LoadSpecificTextures("", "ExpansionCardBackground", 3, &s_backgroundTextures);
	// Expansion L1 Textures
	LoadSpecificTextures("Level1ExpansionCards", "Level1ExpansionCard", GamePieces::s_L1ExpansionCardCount, &s_expansionL2Textures);
	// Expansion L2 Textures
	LoadSpecificTextures("Level2ExpansionCards", "Level2ExpansionCard", GamePieces::s_L2ExpansionCardCount, &s_expansionL2Textures);
	// Expansion L3 Textures
	LoadSpecificTextures("Level3ExpansionCards", "Level3ExpansionCard", GamePieces::s_L3ExpansionCardCount, &s_expansionL3Textures);
	// Noble Textures
	LoadSpecificTextures("NobleCards", "NobleCard", GamePieces::s_NobleCardCount, &s_nobleTextures);
}

void UICard::LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureVector* into)
{
	if (!fileName.empty())
	{
		fileName += '/';
	}
	const std::string path = s_texturesFile + fileName + textureName + "-";
	const std::string fileType = ".png";

	for (uint16_t textureIt = 1; textureIt <= count; ++textureIt)
	{
		std::string current_path = path;
		std::string textureNumber = std::to_string(textureIt);
		if (textureIt < 10)
		{
			textureNumber.insert(textureNumber.begin(), '0');
		}
		current_path += textureNumber + fileType;
		auto* cardTexture = new sf::Texture;
		cardTexture->loadFromFile(current_path);
		into->push_back(cardTexture);
	}
}
