#include "UIGameSession.h"

UIGameSession::UIGameSession(const sf::Vector2u& windowSize)
{
	// instantiate UI components
}

UIGameSession::~UIGameSession()
{
	// delete pointers
}

void UIGameSession::PassEvent(const sf::Event& event)
{
	// iterate colliderVector and call handleEvent(event) on them -> use std::for_each() if you can
}

UIGameSession::Events UIGameSession::GetEvent() const
{
	// evaluate states
}

void UIGameSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// iterate drawableVector and call draw on them -> use std::for_each() if you can
}
