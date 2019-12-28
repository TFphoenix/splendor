#pragma once
#include "UIPanel.h"
#include "RectCollider.h"
#include "UIText.h"

#include <array>

class UIPlayerPanel :public UIPanel, public RectCollider
{
public:
	enum class Type
	{
		User,
		Computer
	};

public:
	// Constr.
	UIPlayerPanel(Type type, const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	// G&S
	bool GetTriggered() const;
	void SetTriggered(bool triggered);

	// Collider Propreties
	void OnMouseEnter() override;
	void OnMouseLeave() override;
	void OnMouseLeftClick() override;
	void OnMouseLeftRelease() override;

	void SetUserTexture(uint16_t textureID);
	static void ShuffleTextures();
	static void LoadIconTextures();

private:
	// Dimensions
	static inline const float s_padding = 0.1f;
	static inline const uint16_t s_fontSize = 40;
	static inline const float s_percentage = 0.40f;
	
	// Textures
	static inline const std::string s_iconsTextureFile = "../external/Resources/Textures/UI/";
	static inline std::array<sf::Texture*, 4> s_userIcons;
	static inline sf::Texture* s_computerIcon;
	static inline bool s_texturesInitialized = false;

private:
	// GUI
	Type m_type;
	bool m_isTriggered;
	sf::RectangleShape m_background;
	sf::CircleShape m_profile;
	UIText m_nameLabel;
	UIText m_prestigeLabel;
	UIText m_clickToViewLabel;

	// Logic
	//Player* p_player;

};

