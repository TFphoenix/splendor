#include "UIPanel.h"

UIPanel::UIPanel(std::string&& name, sf::Vector2f size, bool isActive) :RectangleShape(size), m_name(std::move(name)), m_isActive(isActive) {}

std::string UIPanel::GetName() const
{
	return m_name;
}

void UIPanel::SetName(const std::string& name)
{
	m_name = name;
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
