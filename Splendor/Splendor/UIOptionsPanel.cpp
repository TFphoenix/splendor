#include "UIOptionsPanel.h"

UIOptionsPanel::UIOptionsPanel(const std::string& title, Type type, sf::Vector2f position, sf::Vector2f size, bool isActive) :
	UIPanel(title, size, isActive),
	m_title({ position.x,position.y + size.y / 2.0f }, UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, title, 0.4f * size.y),
	m_type(type)
{
	// Text
	setPosition(position);
	m_title.AlignText(UIText::TextAlign::mid_left);
	m_lastOption = nullptr;
}

void UIOptionsPanel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (IsActive())
	{
		target.draw(m_title);
		for (size_t id = 0; id < GetContentSize(); ++id)
		{
			target.draw(*GetContent(id));
		}
	}
}

void UIOptionsPanel::AddOption(const std::string& optionName)
{
	const float yPosition = getPosition().y;
	if (m_lastOption == nullptr)
	{
		const auto titleBounds = m_title.getGlobalBounds();
		m_lastOption = new UICheckBox(optionName, { titleBounds.left + titleBounds.width,yPosition }, { 200,getSize().y });
		if (m_type == Type::Radio)
		{
			dynamic_cast<UICheckBox*>(m_lastOption)->ChangeState();
			m_lastCheckedID = 0;
		}
	}
	else
	{
		const auto lastBounds = dynamic_cast<UICheckBox*>(m_lastOption)->GetRect();
		m_lastOption = new UICheckBox(optionName, sf::Vector2f(lastBounds.left + lastBounds.width, yPosition), { 200,getSize().y });
	}
	AddContent(m_lastOption);
}

void UIOptionsPanel::HandleEvent(const sf::Event& event)
{
	for (size_t id = 0; id < GetContentSize(); id++)
	{
		GetContent(id)->HandleEvent(event);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			UpdateOptions();
		}
	}
}

void UIOptionsPanel::UpdateOptions()
{
	if (m_type == Type::Radio)
	{
		for (size_t id = 0; id < GetContentSize(); ++id)
		{
			if (dynamic_cast<UICheckBox*>(GetContent(id))->IsChecked())
			{
				if (id != m_lastCheckedID)
				{
					dynamic_cast<UICheckBox*>(GetContent(m_lastCheckedID))->ChangeState();
					m_lastCheckedID = id;
				}
			}
		}
	}
}

