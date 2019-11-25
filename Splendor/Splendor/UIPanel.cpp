#include "UIPanel.h"

UIPanel::UIPanel(std::string&& title, sf::Vector2f size, bool isActive) :RectangleShape(size), m_title(std::move(title)), m_isActive(isActive) {}

std::string UIPanel::GetTitle() const
{
	return m_title;
}

void UIPanel::SetTitle(const std::string& title)
{
	m_title = title;
}

bool UIPanel::IsActive() const
{
	return m_isActive;
}

void UIPanel::SetActive(bool active)
{
	m_isActive = active;
}

void UIPanel::AddContent(Collider* contentItem)
{
	m_content.push_back(contentItem);
}
