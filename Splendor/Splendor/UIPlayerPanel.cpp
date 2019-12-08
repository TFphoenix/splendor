#include "UIPlayerPanel.h"
#include "Randomizer.h"
#include "UIColors.h"

UIPlayerPanel::UIPlayerPanel(Type type, const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("PlayerPanel", size),
	RectCollider(*dynamic_cast<sf::RectangleShape*>(this)),
	m_type(type),
	// Graphic components
	m_nameLabel(sf::Vector2f(position.x + s_percentage * size.x, position.y + s_padding * size.y), UIText::TextAlign::classic, UIText::AvailableFonts::DosisLight, "Player Name", s_fontSize + 10, UIColors::DarkBlue, UIColors::Transparent),
	m_prestigeLabel(sf::Vector2f(position.x + s_percentage * size.x, m_nameLabel.getGlobalBounds().top + m_nameLabel.getGlobalBounds().height), UIText::TextAlign::classic, UIText::AvailableFonts::DosisBold, "Prestige Points: 0", s_fontSize - 10, UIColors::DarkBlue, UIColors::Transparent),
	m_clickToViewLabel(sf::Vector2f(position.x + s_percentage * size.x, m_prestigeLabel.getGlobalBounds().top + m_prestigeLabel.getGlobalBounds().height + s_padding * size.y / 2), UIText::TextAlign::classic, UIText::AvailableFonts::DosisLight, "(Click to view hand)", s_fontSize - 10, UIColors::DarkBlue, UIColors::Transparent)
{
	// Re-scale UIText
	const auto scale = (size.y - 4 * size.y * s_padding) / (m_nameLabel.getGlobalBounds().top + m_nameLabel.getGlobalBounds().height);
	m_nameLabel.setScale(scale, scale);
	m_prestigeLabel.setScale(scale, scale);
	m_clickToViewLabel.setScale(scale, scale);
	// Re-position UIText
	m_nameLabel.setPosition(m_nameLabel.getPosition().x, position.y + s_padding * size.y);
	m_prestigeLabel.setPosition(m_prestigeLabel.getPosition().x, m_nameLabel.getGlobalBounds().top + m_nameLabel.getGlobalBounds().height);
	m_clickToViewLabel.setPosition(m_clickToViewLabel.getPosition().x, position.y + size.y - 2 * s_padding * size.y - m_clickToViewLabel.getGlobalBounds().height);

	// Textures
	if (!s_texturesInitialized)
	{
		s_texturesInitialized = true;
		LoadIconTextures();
	}

	// Profile
	m_profile.setRadius((size.y - 2 * s_padding * size.y) / 2);
	m_profile.setOrigin(m_profile.getRadius(), m_profile.getRadius());
	m_profile.setPosition(position.x + (size.x * s_percentage) / 2, position.y + size.y / 2);
	m_profile.setTexture(s_userIcons[0]);

	//Background
	m_background.setSize(size);
	m_background.setPosition(position);
	m_background.setFillColor(UIColors::GoldYellow);

	// Add drawable content to panel
	AddContent(dynamic_cast<Drawable*>(&m_background));
	AddContent(dynamic_cast<Drawable*>(&m_profile));
	AddContent(dynamic_cast<Drawable*>(&m_nameLabel));
	AddContent(dynamic_cast<Drawable*>(&m_prestigeLabel));
	AddContent(dynamic_cast<Drawable*>(&m_clickToViewLabel));
}

void UIPlayerPanel::OnMouseEnter()
{
}

void UIPlayerPanel::OnMouseLeave()
{
}

void UIPlayerPanel::OnMouseLeftRelease()
{
}

void UIPlayerPanel::LoadIconTextures()
{
	s_computerIcon = new sf::Texture;
	s_computerIcon->loadFromFile(s_iconsTextureFile + "/computer.png");
	char textureID = '1';
	std::for_each(s_userIcons.begin(), s_userIcons.end(), [&textureID](sf::Texture*& texture)
		{
			texture = new sf::Texture;
			texture->loadFromFile(s_iconsTextureFile + "/user" + textureID + ".png");
			++textureID;
		});
	Randomizer::Shuffle(s_userIcons);
}
