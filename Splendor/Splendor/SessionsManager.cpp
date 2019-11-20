#include "SessionsManager.h"
#include "PregameSetup.h"
#include "Deck.h"
#include "ExpansionCard.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>

SessionsManager::SessionsManager()
{
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	window = new sf::RenderWindow(desktop, "Splendor", sf::Style::None);
}

void SessionsManager::MainSession()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	int x = 0;

	sf::Clock clock;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		sf::Time dt = clock.restart();

		x++;
		if (x > 100) {
			x = 0;
		}

		window->clear();
		shape.setOrigin(x, 0);
		window->draw(shape);
		window->display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			return;
		}
	}

	return;
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

