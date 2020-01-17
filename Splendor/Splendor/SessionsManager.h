#pragma once
#include <SFML/Graphics.hpp>
#include "../Logging/Logger.h"

#include <fstream>

class PregameSetup;

class SessionsManager
{
public:
	SessionsManager();
	~SessionsManager();

	void MainMenuSession() const;
	void PreGameSession() const;
	void TutorialSession() const;
	void GameSessionOffline(const PregameSetup& pregameSetup) const;
	void GameSessionOnline(const PregameSetup& pregameSetup) const;
	void TestSession() const;

private:
	static inline const std::string s_logFile = "./Log/LogFile.log";

private:
	// Window
	sf::RenderWindow* window;
	sf::Vector2i windowPosition;
	sf::Vector2u windowSize;

	// Logger
	Logger logger;
	std::ofstream logFileStream;
};