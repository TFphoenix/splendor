#include "UIPanel.h"

UIPanel::UIPanel(const std::string& title, const sf::Vector2f& size, bool isActive) :RectangleShape(size), m_titleString(title), m_isActive(isActive) {}

std::string UIPanel::GetTitle() const
{
	return m_titleString;
}

void UIPanel::SetTitle(const std::string& title)
{
	m_titleString = title;
}

bool UIPanel::IsActive() const
{
	return m_isActive;
}

void UIPanel::SetActive(bool active)
{
	m_isActive = active;
}

Collider* UIPanel::GetContentCollider(unsigned contentID) const
{
	if (contentID < m_content.size())
		return m_content[contentID].first;
	return nullptr;
}

sf::Drawable* UIPanel::GetContentDrawable(unsigned contentID) const
{
	if (contentID < m_content.size())
		return m_content[contentID].second;
	return nullptr;
}

size_t UIPanel::ContentSize() const
{
	return m_content.size();
}

void UIPanel::AddContent(std::pair<Collider*, sf::Drawable*> contentItem)
{
	m_content.push_back(contentItem);
}
