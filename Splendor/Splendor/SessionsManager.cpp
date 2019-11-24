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
	/*const sf::VideoMode desktopVM = sf::VideoMode().getDesktopMode();
	window = new sf::RenderWindow(desktopVM, "Splendor", sf::Style::None);*/
	const sf::VideoMode windowedVM = sf::VideoMode(800, 500);
	window = new sf::RenderWindow(windowedVM, "Splendor", sf::Style::None);
}

void SessionsManager::MainSession()
{
	sf::RectangleShape shape(sf::Vector2f(200, 100));
	shape.setPosition(sf::Vector2f(100, 100));
	//UIButton::Design noneDesign, hoverDesign, pressDesign;
	Collider* button = new UIButton(shape/*, noneDesign, hoverDesign, pressDesign*/);


	window->clear();
	dynamic_cast<UIButton*>(button)->Draw(window);
	window->display();
	
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			button->HandleEvent(event);
		}

		window->clear();
		dynamic_cast<UIButton*>(button)->Draw(window);
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

