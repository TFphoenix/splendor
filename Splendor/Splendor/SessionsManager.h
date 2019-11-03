#pragma once
#include <SFML/Graphics.hpp>

class SessionsManager
{
public:
	SessionsManager();
	void MainSession();
	
private:
	sf::RenderWindow* m_window;
	
};

