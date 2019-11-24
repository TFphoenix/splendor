#pragma once
#include <SFML/Graphics.hpp>

class SessionsManager
{
public:
	SessionsManager();
	~SessionsManager();
	
	void MainMenuSession() const;
	void PreGameSession() const;
	void GameSession() const;
	void TestSession() const;

private:
	sf::RenderWindow* window;
	sf::Vector2i windowPosition;
	sf::Vector2u windowSize;
};

