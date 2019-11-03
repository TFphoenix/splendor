#pragma once
#include <SFML/Graphics.hpp>

class SessionsManager
{
public:
	SessionsManager();
	void MainSession();
	void GameSession();
	
private:
	sf::RenderWindow* m_window;
	
};

