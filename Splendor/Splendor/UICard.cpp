#include "UICard.h"
#include "GamePieces.h"
#include <thread>

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
	std::thread thread1(LoadSpecificTextures, "", "ExpansionCardBackground", 3, &s_backgroundTextures);
	// Expansion L1 Textures
	std::thread thread2(LoadSpecificTextures, "Level1ExpansionCards", "Level1ExpansionCard", GamePieces::s_L1ExpansionCardCount, &s_expansionL2Textures);
	// Expansion L2 Textures
	std::thread thread3(LoadSpecificTextures, "Level2ExpansionCards", "Level2ExpansionCard", GamePieces::s_L2ExpansionCardCount, &s_expansionL2Textures);
	// Expansion L3 Textures
	std::thread thread4(LoadSpecificTextures, "Level3ExpansionCards", "Level3ExpansionCard", GamePieces::s_L3ExpansionCardCount, &s_expansionL3Textures);
	// Noble Textures
	std::thread thread5(LoadSpecificTextures, "NobleCards", "NobleCard", GamePieces::s_NobleCardCount, &s_nobleTextures);

	// Join Threads
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
}

void UICard::LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureVector* into)
{
	// construct general path
	if (!fileName.empty())
	{
		fileName += '/';
	}
	const std::string path = s_texturesFile + fileName + textureName + "-";
	const std::string fileType = ".png";

	//std::mutex mutex;
	//std::vector<std::thread> threads;
	for (uint16_t textureIt = 1; textureIt <= count; ++textureIt)
	{
		// construct specific path
		std::string current_path = path;
		std::string textureNumber = std::to_string(textureIt);
		if (textureIt < 10)
		{
			textureNumber.insert(textureNumber.begin(), '0');
		}
		current_path += textureNumber + fileType;
		LoadSpecificTexture(current_path, into);
		//threads.emplace_back(LoadSpecificTexture, current_path, into);
	}
	/*for (auto& thread : threads)
	{
		thread.join();
	}*/
}

void UICard::LoadSpecificTexture(const std::string& path, TextureVector* into)
{
	//std::lock_guard<std::mutex> guard(s_mutex);
	auto* cardTexture = new sf::Texture;
	cardTexture->loadFromFile(path);
	into->push_back(cardTexture);
}
