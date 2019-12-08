#include "UIVTokensPanel.h"
#include "GamePieces.h"

UIVTokensPanel::UIVTokensPanel(const sf::Vector2f& position, const sf::Vector2f& size, bool isActive) :
	UIPanel("UIVTokensPanel", size, position, isActive)
{
	const auto tokenRadius = s_tokenPercentage * size.y / 2;
	for (uint16_t tokenIt = 0; tokenIt < 6; ++tokenIt)
	{
		// UIToken
		m_tokens[tokenIt] = new UIToken(static_cast<IToken::Type>(tokenIt), sf::Vector2f(0, 0), tokenRadius);
		auto& tokenBody = m_tokens[tokenIt]->GetBody();
		tokenBody.setOrigin(tokenRadius, tokenRadius);
		tokenBody.setPosition(position.x + size.x / 2, position.y + tokenRadius + (tokenIt + 1) * s_yPaddingPercentage * size.y + tokenIt * 2 * tokenRadius);
		AddContent(dynamic_cast<sf::Drawable*>(m_tokens[tokenIt]));
		AddContent(dynamic_cast<Collider*>(m_tokens[tokenIt]));

		// UIText
		m_tokensText[tokenIt] = new UIText(sf::Vector2f(tokenBody.getPosition().x + s_xPaddingPercentage * size.x * 4, tokenBody.getPosition().y), UIText::TextAlign::classic, UIText::AvailableFonts::DosisBold, std::to_string(GamePieces::GetGemTokenCount()), 60);
		m_tokensText[tokenIt]->AlignText(UIText::TextAlign::mid_center);
		m_tokensText[tokenIt]->setPosition(sf::Vector2f(tokenBody.getPosition().x + tokenRadius - 6 * s_xPaddingPercentage * size.x, tokenBody.getPosition().y + tokenRadius - 6 * s_xPaddingPercentage * size.x));
		AddContent(dynamic_cast<sf::Drawable*>(m_tokensText[tokenIt]));
	}
	m_tokensText[5]->setString(std::to_string(GamePieces::s_GoldTokenCount));
}
