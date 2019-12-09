#pragma once
#include <array>
#include <optional>

#include "UIPanel.h"
#include "UIToken.h"
#include "UIText.h"


class UIVTokensPanel :public UIPanel
{
public:
	using PickedArray = std::array<std::optional<IToken::Type>, 3>;

public:
	UIVTokensPanel(const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 100,1024 }, bool isActive = true);

	// Logic
	void UpdateTokens();
	PickedArray& ExtractPickedTokens();

private:
	// picked tokens
	bool PickedTokensFull() const;
	void AddPickedToken(IToken::Type tokenType);

private:
	static inline const float s_xPaddingPercentage = 0.02f;
	static inline const float s_yPaddingPercentage = 0.04f;
	static inline const float s_tokenPercentage = 0.12f;

private:
	std::array<UIToken*, 6> m_tokens;
	std::array<UIText*, 6> m_tokensText;
	PickedArray m_pickedTokens;

};

