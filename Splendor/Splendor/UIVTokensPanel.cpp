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
		m_tokens[tokenIt]->SetOrigin(tokenRadius, tokenRadius);
		m_tokens[tokenIt]->SetPosition(position.x + size.x / 2, position.y + tokenRadius + (tokenIt + 1) * s_yPaddingPercentage * size.y + tokenIt * 2 * tokenRadius);
		auto tokenBody = m_tokens[tokenIt]->GetBody();
		AddContent(dynamic_cast<sf::Drawable*>(m_tokens[tokenIt]));
		AddContent(dynamic_cast<Collider*>(m_tokens[tokenIt]));

		// UIText
		m_tokensText[tokenIt] = new UIText(sf::Vector2f(tokenBody.getPosition().x + tokenRadius, tokenBody.getPosition().y + tokenRadius), UIText::TextAlign::classic, UIText::AvailableFonts::BerlinBold, std::to_string(GamePieces::GetGemTokenCount()), 60);
		m_tokensText[tokenIt]->AlignText(UIText::TextAlign::mid_center);
		m_tokensText[tokenIt]->setPosition(sf::Vector2f(tokenBody.getPosition().x + tokenRadius - 6 * s_xPaddingPercentage * size.x, tokenBody.getPosition().y + tokenRadius - 6 * s_xPaddingPercentage * size.x));
		AddContent(dynamic_cast<sf::Drawable*>(m_tokensText[tokenIt]));
	}
	m_tokens[5]->SetNumb(true);
	m_tokensText[5]->setString(std::to_string(GamePieces::s_GoldTokenCount));
}

void UIVTokensPanel::UpdateTokens()
{
	uint16_t it = 0;
	for (const auto& token : m_tokens)
	{
		if (token->GetState() == UIToken::State::Release)
		{
			if (!PickedTokensFull())
			{
				// Add to picked tokens
				AddPickedToken(token->GetType());

				// Update text
				token->SetState(UIToken::State::Hover);
				std::string newString(m_tokensText[it]->getString());
				if (newString != "0")
				{
					newString[0]--;
					m_tokensText[it]->setString(newString);
				}
			}
		}
		++it;
	}
}

UIVTokensPanel::PickedArray& UIVTokensPanel::ExtractPickedTokens()
{
	return m_pickedTokens;
}

bool UIVTokensPanel::PickedTokensFull() const
{
	if (m_pickedTokens[2].has_value())
		return true;
	if (!m_pickedTokens[1].has_value())
		return false;
	if (m_pickedTokens[0] == m_pickedTokens[1])
		return true;
	return false;
}

void UIVTokensPanel::AddPickedToken(IToken::Type tokenType)
{
	if (!m_pickedTokens[0].has_value())
		m_pickedTokens[0] = tokenType;
	else if (!m_pickedTokens[1].has_value())
		m_pickedTokens[1] = tokenType;
	else
		m_pickedTokens[2] = tokenType;
}
