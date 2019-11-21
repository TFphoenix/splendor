#include "SessionsManager.h"
#include "PregameSetup.h"
#include "Deck.h"
#include "ExpansionCard.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>

SessionsManager::SessionsManager()
{
	/*sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	window = new sf::RenderWindow(desktop, "Splendor", sf::Style::None);*/
	sf::VideoMode windowed = sf::VideoMode(800, 500);
	window = new sf::RenderWindow(windowed, "Splendor", sf::Style::None);
}

void SessionsManager::MainSession()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->draw(shape);
		window->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			return;
		}
	}
}

void SessionsManager::GameSession()
{
	uint16_t playerCount;
	std::cin >> playerCount;

	try
	{
		PregameSetup pregameSetup(playerCount);
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage;
	}
}

void SessionsManager::TestSession()
{

}

