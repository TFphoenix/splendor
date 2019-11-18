#pragma once
//#include <SFML/Graphics.hpp>
#include"State.h"
#include "GameState.h"
#include "MainMenuState.h"
class SessionsManager
{
public:
	SessionsManager();
	virtual ~SessionsManager();
	void MainSession();
	void GameSession();
	void TestSession();
	
	void endApplication();

	void updateDt();
	void updateEvents();
	void update();

	void render();


	void Test1Session();
	
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSetting;
	bool fullscreen;

	void initVariables();
	void initWindows();
	void initKeys();
	void initStates();
	
};

