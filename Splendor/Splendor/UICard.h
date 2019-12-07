#pragma once
#include "RectCollider.h"
#include "ICard.h"

#include <SFML/Graphics.hpp>
#include <mutex>
#include <unordered_map>

class UICard :public RectCollider, public sf::RectangleShape
{
public:
	using TextureMap = std::unordered_map<uint16_t, sf::Texture*>;

public:
	UICard(/*Add ID*/const sf::Vector2f& position = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(0, 0));

	//GetID
	//SetID

private:
	static void LoadTextures();
	static void LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureMap* into);
	static void LoadSpecificTexture(const std::string& path, TextureMap* into, uint16_t atID);
	//const sf::Texture& GetTexture(//ID);//Gets texture by DAO ID

private:
	const inline static std::string s_texturesFile = "../external/Resources/Textures/Cards/HQTextures/";
	static inline TextureMap s_backgroundTextures;
	static inline TextureMap s_expansionL1Textures;
	static inline TextureMap s_expansionL2Textures;
	static inline TextureMap s_expansionL3Textures;
	static inline TextureMap s_nobleTextures;
	static inline bool s_texturesLoaded = false;
	static inline std::mutex s_mutex;

private:
	//ID
};