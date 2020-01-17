#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "SessionsManager.h"
#include "PregameSetup.h"
#include "UIColors.h"
#include "UIMainMenuSession.h"
#include "UIPreGameSession.h"
#include "UIGameSession.h"
#include "UITutorialSession.h"
#include "CardDAO.h"
#include "Player.h"
#include "SoundSystem.h"
#include "Network.h"


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

	SoundSystem::LoadFromFile();
	SoundSystem::PlayMusic(SoundSystem::MusicType::MenuMusic);




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
				logger.Log("Starting Tutorial Session...", Logger::Level::Info);

				TutorialSession();
				break;
			case UIMainMenuSession::Events::Settings:
				// Settings Session
				break;
			case UIMainMenuSession::Events::Exit:
				SoundSystem::StopMusic(SoundSystem::MusicType::MenuMusic);
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

void SessionsManager::TutorialSession() const
{
	logger.Log("Entered Tutorial Session", Logger::Level::Info);
	UITutorialSession tutorialSessionGUI(windowSize);
	logger.Log("Initialized Tutorial GUI", Logger::Level::Info);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			tutorialSessionGUI.PassEvent(event);
			switch (tutorialSessionGUI.GetEvent())
			{
			case UITutorialSession::Events::MainMenu:
				logger.Log("Exiting Tutorial Session...", Logger::Level::Info);
				return;
			default:
				break;
			}
		}

		window->clear(UIColors::NavyBlue);
		window->draw(tutorialSessionGUI);
		window->display();
	}

}

void SessionsManager::GameSession(const PregameSetup& pregameSetup) const
{
	logger.Log("Entered Game Session", Logger::Level::Info);
	// Testing Networking
	Network network;
	switch (pregameSetup.GetGameMode())
	{
	case PregameSetup::GameMode::Client:
	{
		network.InitialiseClient();
		break;
	}
	case PregameSetup::GameMode::Server:
	{
		network.InitialiseServer();
		network.AcceptConnection();
		break;
	}
	default:
		break;
	}


	// Initialize Database
	CardDAO cardsDatabase;
	logger.Log("Initialized Cards Database", Logger::Level::Info);

	//Game Music sound on
	SoundSystem::StopMusic(SoundSystem::MusicType::MenuMusic);
	SoundSystem::PlayMusic(SoundSystem::MusicType::GameMusic);

	// Initialize Players
	std::vector<Player> players;
	for (size_t playerNr = 1; playerNr <= pregameSetup.GetPlayerCount(); ++playerNr)
	{
		players.emplace_back(playerNr, "Player " + std::to_string(playerNr));
	}
	size_t activePlayerIterator = 0;
	std::reference_wrapper<Player> activePlayer = players[activePlayerIterator];

	// Initialize Board
	Board board;

	// Initialize GUI
	UIGameSession gameSessionGUI(windowSize, pregameSetup, &players, &board, activePlayer);
	logger.Log("Initialized Game GUI", Logger::Level::Info);

	// Test
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::RedRuby);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::BlackOnyx);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::WhiteDiamond);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::GreenEmerald);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);
	players[0].GetHand().AddResource(IToken::Type::BlueSapphire);



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
				SoundSystem::StopMusic(SoundSystem::MusicType::GameMusic);
				SoundSystem::PlayMusic(SoundSystem::MusicType::MenuMusic);
				return;
			case UIGameSession::Events::PassButton:
				gameSessionGUI.NextTurn();
				++activePlayerIterator;
				if (activePlayerIterator == pregameSetup.GetPlayerCount())
					activePlayerIterator = 0;
				activePlayer = players[activePlayerIterator];
				break;
			default:
				break;
			}
		}

		// Game Logic
		// (Transfer everything to a Game Controller)
		// ...

		// Update & Display
		gameSessionGUI.UpdateGame();
		window->clear(UIColors::NavyBlue);
		window->draw(gameSessionGUI);
		window->display();
	}
}

void SessionsManager::TestSession() const
{
	//SoundSystem::PlayMusic(SoundSystem::MusicType::MenuMusic);


}