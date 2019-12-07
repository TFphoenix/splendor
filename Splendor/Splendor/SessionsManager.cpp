#include "SessionsManager.h"
#include "PregameSetup.h"
#include "ExpansionCard.h"
#include "UIButton.h"
#include "UIColors.h"
#include "UIMainMenuSession.h"
#include "UIPreGameSession.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "UICard.h"
#include "../Logging/Logger.h"

SessionsManager::SessionsManager()
{
	const sf::VideoMode desktopVM = sf::VideoMode().getDesktopMode();
	const sf::VideoMode windowedVM = sf::VideoMode(1280, 720);

	window = new sf::RenderWindow(desktopVM, "Splendor", sf::Style::None);
	//window = new sf::RenderWindow(windowedVM, "Splendor", sf::Style::None);

	windowPosition = window->getPosition();
	windowSize = window->getSize();
}

SessionsManager::~SessionsManager()
{
	delete window;
}

void SessionsManager::MainMenuSession() const
{
	UIMainMenuSession mainMenuSessionGUI(windowSize);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			mainMenuSessionGUI.PassEvent(event);
			switch (mainMenuSessionGUI.GetEvent()) {
			case UIMainMenuSession::Events::NewGame:
				PreGameSession();
				break;
			case UIMainMenuSession::Events::Tutorial:
				// Tutorial Session
				break;
			case UIMainMenuSession::Events::Settings:
				// Settings Session
				break;
			case UIMainMenuSession::Events::Exit:
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
	/*uint16_t playerCount;
	std::cin >> playerCount;

	try
	{
		PregameSetup pregameSetup(playerCount);
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage;
	}*/
	UIPreGameSession pregameSessionGUI(windowSize);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			pregameSessionGUI.PassEvent(event);
			switch (pregameSessionGUI.GetEvent())
			{
			case UIPreGameSession::Events::MainMenu:
				return;
			case UIPreGameSession::Events::StartGame:
				GameSession();
				return;
			default:
				break;
			}
		}

		window->clear(UIColors::DarkBlue);
		window->draw(pregameSessionGUI);
		window->display();
	}
}

void SessionsManager::GameSession() const
{
	UICard test_card(3, UICard::Type::Background, { 0,0 }, { 238,357 });
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					return;
				}
			}
		}
		window->clear(UIColors::DarkBlue);
		window->draw(test_card);
		window->display();
	}
}

void SessionsManager::TestSession() const
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Application started.", Logger::Level::Info);
	std::cout << "ENTERED TEST SESSION\n";
}