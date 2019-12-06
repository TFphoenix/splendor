#pragma once
#include "RectCollider.h"
#include "ICard.h"

#include <SFML/Graphics.hpp>

class UICard :public RectCollider, public sf::RectangleShape
{
public:
	using TextureVector = std::vector<sf::Texture*>;

public:
	UICard(/*Add ID*/const sf::Vector2f& position = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(0, 0));

	//GetID
	//SetID

private:
	static void LoadTextures();
	static void LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureVector* into);
	//const sf::Texture& GetTexture(//ID);//Gets texture by DAO ID

private:
	const inline static std::string s_texturesFile = "../external/Resources/Textures/Cards/";
	static inline TextureVector s_backgroundTextures;
	static inline TextureVector s_expansionL1Textures;
	static inline TextureVector s_expansionL2Textures;
	static inline TextureVector s_expansionL3Textures;
	static inline TextureVector s_nobleTextures;
	static inline bool s_texturesLoaded = false;

private:
	//ID
};