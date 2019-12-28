#include <SFML/Graphics.hpp>

#include "SessionsManager.h"
#include "PregameSetup.h"
#include "UIColors.h"
#include "UIMainMenuSession.h"
#include "UIPreGameSession.h"
#include "UIGameSession.h"
#include "CardDAO.h"
#include "Player.h"

SessionsManager::SessionsManager() :
	logger(logFileStream, Logger::Level::Error),
	logFileStream(s_logFile, std::ios::app)
{
	logger.Log("Application started", Logger::Level::Info);
	const sf::VideoMode desktopVM = sf::VideoMode().getDesktopMode();
	const sf::VideoMode windowedVM = sf::VideoMode(1280, 720);

	window = new sf::RenderWindow(desktopVM, "Splendor", sf::Style::None);
	//window = new sf::RenderWindow(windowedVM, "Splendor", sf::Style::None);

	logger.Log("Window created", Logger::Level::Info);

	windowPosition = window->getPosition();
	windowSize = window->getSize();
}

SessionsManager::~SessionsManager()
{
	delete window;
	logger.Log("Window deleted\n\n", Logger::Level::Info);
}

void SessionsManager::MainMenuSession() const
{
	logger.Log("Entered Main Menu Session", Logger::Level::Info);
	UIMainMenuSession mainMenuSessionGUI(windowSize);
	logger.Log("Initialized Main Menu GUI", Logger::Level::Info);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			mainMenuSessionGUI.PassEvent(event);
			switch (mainMenuSessionGUI.GetEvent()) {
			case UIMainMenuSession::Events::NewGame:
				logger.Log("Starting PreGame Session...", Logger::Level::Info);
				PreGameSession();
				break;
			case UIMainMenuSession::Events::Tutorial:
				// Tutorial Session
				break;
			case UIMainMenuSession::Events::Settings:
				// Settings Session
				break;
			case UIMainMenuSession::Events::Exit:
				logger.Log("Exiting Main Menu Session...", Logger::Level::Info);
				return;
			case UIMainMenuSession::Events::Test:
				TestSession();
				break;
			default:
				break;
			}
		}

		window->clear();
		window->draw(mainMenuSessionGUI);
		window->display();
	}
}

void SessionsManager::PreGameSession() const
{
	logger.Log("Entered PreGame Session", Logger::Level::Info);
	UIPreGameSession pregameSessionGUI(windowSize);
	logger.Log("Initialized PreGame GUI", Logger::Level::Info);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			pregameSessionGUI.PassEvent(event);
			switch (pregameSessionGUI.GetEvent())
			{
			case UIPreGameSession::Events::MainMenu:
				logger.Log("Exiting PreGame Session...", Logger::Level::Info);
				return;
			case UIPreGameSession::Events::StartGame:
				logger.Log("Starting Game Session...", Logger::Level::Info);
				GameSession(pregameSessionGUI.GetPregameSetup());
				return;
			default:
				break;
			}
		}

		window->clear(UIColors::NavyBlue);
		window->draw(pregameSessionGUI);
		window->display();
	}
}

void SessionsManager::GameSession(const PregameSetup& pregameSetup) const
{
	logger.Log("Entered Game Session", Logger::Level::Info);

	// Initialize Database
	CardDAO cardsDatabase;
	logger.Log("Initialized Cards Database", Logger::Level::Info);

	// Initialize Players
	std::vector<Player> players;
	for (size_t playerNr = 1; playerNr <= pregameSetup.GetPlayerCount(); ++playerNr)
	{
		players.emplace_back("Player " + std::to_string(playerNr));
	}

	// Initialize Board
	Board board;

	// Initialize GUI
	UIGameSession gameSessionGUI(windowSize, pregameSetup, &players, &board);
	logger.Log("Initialized Game GUI", Logger::Level::Info);



	// Game Loop
	gameSessionGUI.StartGame();
	logger.Log("Game started", Logger::Level::Info);
	while (window->isOpen())
	{
		// Event Handling
		sf::Event event;
		while (window->pollEvent(event))
		{
			gameSessionGUI.PassEvent(event);
			switch (gameSessionGUI.GetEvent())
			{
			case UIGameSession::Events::MenuButton:
				return;
			default:
				break;
			}
		}

		// Update & Display
		gameSessionGUI.UpdateGame();
		window->clear(UIColors::NavyBlue);
		window->draw(gameSessionGUI);
		window->display();
	}
}

void SessionsManager::TestSession() const
{
}