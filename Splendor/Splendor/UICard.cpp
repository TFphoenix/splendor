#include "UICard.h"
#include "GamePieces.h"
#include "UIColors.h"
#include "UISelectedCard.h"

#include <thread>

UICard::Data::Data(Type dataType, uint16_t dataID) :type(dataType), id(dataID) {}

UICard::UICard(uint16_t id, Type type, const sf::Vector2f& position, const sf::Vector2f& size) :
	RectCollider(position, size),
	RectangleShape(size),
	m_initialPosition(position),
	m_numb(false),
	m_state(State::None),
	m_data(type, id)
{
	// Initialize
	setPosition(position);
	if (!s_texturesLoaded)
	{
		LoadTextures();
		s_texturesLoaded = true;
	}

	// Set texture
	const sf::Texture* texture = GetTexture(id, type);
	if (texture != nullptr)
	{
		setTexture(texture);
	}

	// Animation
	setOutlineThickness(0.05f * size.x);
	setOutlineColor(UIColors::Transparent);
}

uint16_t UICard::GetID() const
{
	return m_data.id;
}

UICard::Type UICard::GetType() const
{
	return m_data.type;
}

UICard::Data UICard::GetData() const
{
	return m_data;
}

void UICard::SetData(Data data)
{
	const sf::Texture* texture = GetTexture(data.id, data.type);
	if (texture != nullptr)
	{
		m_data = data;
		setTexture(texture);
	}
}

bool UICard::GetNumb() const
{
	return m_numb;
}

void UICard::SetNumb(bool numb)
{
	m_numb = numb;
}

void UICard::OnMouseOver()
{
	if (!m_numb)
	{
		setPosition(sf::Mouse::getPosition().x - getSize().x, sf::Mouse::getPosition().y - getSize().y);
	}
}

void UICard::OnMouseEnter()
{
	if (!m_numb)
	{
		m_state = State::Hover;
		setScale(2, 2);
		setOutlineColor(UIColors::GoldYellow - UIColors::HalfTransparent);
		UISelectedCard::Set(dynamic_cast<sf::Drawable*>(this));
	}
}

void UICard::OnMouseLeave()
{
	if (!m_numb)
	{
		m_state = State::None;
		setScale(1, 1);
		setOutlineColor(UIColors::Transparent);
		setPosition(m_initialPosition);
		UISelectedCard::Set(nullptr);
	}
}

void UICard::OnMouseLeftClick()
{
	if (!m_numb)
	{
		m_state = State::Press;
		setScale(1.8, 1.8);
		setOutlineColor(UIColors::DarkYellow - UIColors::HalfTransparent);
	}
}

void UICard::OnMouseLeftRelease()
{
	if (!m_numb)
	{
		m_state = State::Release;
		setScale(2, 2);
		setOutlineColor(UIColors::GoldYellow - UIColors::HalfTransparent);
	}
}

void UICard::LoadTextures()
{
	// Background Textures
	std::thread thread1(LoadSpecificTextures, "", "ExpansionCardBackground", 3, &s_backgroundTextures);
	// Expansion L1 Textures
	std::thread thread2(LoadSpecificTextures, "Level1ExpansionCards", "Level1ExpansionCard", GamePieces::s_L1ExpansionCardCount, &s_expansionL1Textures);
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

void UICard::LoadSpecificTextures(std::string&& fileName, const std::string&& textureName, uint16_t count, TextureMap* into)
{
	// construct general path
	if (!fileName.empty())
	{
		fileName += '/';
	}
	const std::string path = s_texturesFile + fileName + textureName + "-";
	const std::string fileType = ".png";

	// run threads and populate TextureMaps
	std::vector<std::thread> threads;
	for (uint16_t textureID = 1; textureID <= count; ++textureID)
	{
		// construct specific path
		std::string current_path = path;
		std::string textureNumber = std::to_string(textureID);
		if (textureID < 10)
		{
			textureNumber.insert(textureNumber.begin(), '0');
		}
		current_path += textureNumber + fileType;
		threads.emplace_back(LoadSpecificTexture, current_path, into, textureID);
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
}

void UICard::LoadSpecificTexture(const std::string& path, TextureMap* into, uint16_t atID)
{
	auto* cardTexture = new sf::Texture;
	cardTexture->loadFromFile(path);
	(*into)[atID] = cardTexture;
}

const sf::Texture* UICard::GetTexture(uint16_t id, Type type)
{
	switch (type)
	{
	case Type::Background:
		try
		{
			return s_backgroundTextures[id];
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Wrong id or type");
		}
	case Type::ExpansionL1:
		try
		{
			return s_expansionL1Textures[id];
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Wrong id or type");
		}
	case Type::ExpansionL2:
		try {
			return s_expansionL2Textures[id];
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Wrong id or type");
		}
	case Type::ExpansionL3:
		try
		{
			return s_expansionL3Textures[id];
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Wrong id or type");
		}
	case Type::Noble:
		try
		{
			return s_nobleTextures[id];
		}
		catch (std::exception)
		{
			throw std::invalid_argument("Wrong id or type");
		}
	case Type::Unknown:
		return nullptr;
	default:
		throw std::invalid_argument("Wrong id or type");
	}
}