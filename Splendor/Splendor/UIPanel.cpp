#include "UIPanel.h"

UIPanel::UIPanel(const std::string& title, sf::Vector2f size, bool isActive) :RectangleShape(size), m_titleString(title), m_isActive(isActive) {}

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

std::pair<Collider*, sf::Drawable*> UIPanel::GetContent(size_t contentID) const
{
	if (contentID < m_content.size())
		return m_content[contentID];
	return *m_content.end();
}

size_t UIPanel::GetContentSize() const
{
	return m_content.size();
}

void UIPanel::AddContent(std::pair<Collider*, sf::Drawable*> contentItem)
{
	m_content.push_back(contentItem);
}
