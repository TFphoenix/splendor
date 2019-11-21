#include "SessionsManager.h"
#include "PregameSetup.h"
#include "Deck.h"
#include "ExpansionCard.h"
#include "UIButton.h"

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
	sf::RectangleShape shape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Green);
	//Collider* button = new UIButton(shape, UIButton::Design(sf::Color::Blue), UIButton::Design(sf::Color::Red), UIButton::Design(sf::Color::Cyan));

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			//button->HandleEvent(event);
		}

		window->clear();
		//dynamic_cast<UIButton*>(button)->Draw(window);
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

