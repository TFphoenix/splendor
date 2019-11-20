#pragma once
#include <SFML/Graphics.hpp>

class SessionsManager
{
public:
	SessionsManager();
	void MainSession();
	void GameSession();
	void TestSession();
	
private:
	sf::RenderWindow* window;
};

