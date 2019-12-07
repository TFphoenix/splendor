#pragma once
#include "RectCollider.h"
#include "ICard.h"

#include <SFML/Graphics.hpp>
#include <unordered_map>

class UICard :public RectCollider, public sf::RectangleShape
{
public:
	using TextureMap = std::unordered_map<uint16_t, sf::Texture*>;

public:
	enum class Type
	{
		Background,
		ExpansionL1,
		ExpansionL2,
		ExpansionL3,
		Noble
	};

public:
	UICard(uint16_t id, Type type, const sf::Vector2f& position = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(0, 0));

	// Manipulators
	uint16_t GetID() const;
	Type GetType() const;
	//void ChangeID(uint16_t newID);
	//void ChangeType(Type newType);

private:
	static void LoadTextures();
	static void LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureMap* into);
	static void LoadSpecificTexture(const std::string& path, TextureMap* into, uint16_t atID);
	static const sf::Texture* GetTexture(uint16_t id, Type type);

private:
	const inline static std::string s_texturesFile = "../external/Resources/Textures/Cards/";
	static inline TextureMap s_backgroundTextures;
	static inline TextureMap s_expansionL1Textures;
	static inline TextureMap s_expansionL2Textures;
	static inline TextureMap s_expansionL3Textures;
	static inline TextureMap s_nobleTextures;
	static inline bool s_texturesLoaded = false;

private:
	uint16_t m_id;
	Type m_type;
};