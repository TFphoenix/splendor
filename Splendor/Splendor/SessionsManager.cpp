#include "SessionsManager.h"
#include "PregameSetup.h"
#include "Deck.h"
#include "ExpansionCard.h"

#include <SFML/Graphics.hpp>

#include <iostream>

SessionsManager::SessionsManager()
{
	//window = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML works!");
	this->initWindows();
	this->initKeys();
	this->initStates();

}

SessionsManager::~SessionsManager()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
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
	Deck<ExpansionCard> deck;
	deck.AddCard(ExpansionCard(ExpansionCard::Level::Level1, IToken::Type::BlackOnyx, 0, 2, 2, 3, 0));
	deck.DrawCard();
}

void SessionsManager::endApplication()
{
	std::cout << "Ending Application" << "\n";
}

void SessionsManager::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
	
	
}

void SessionsManager::initWindows()
{
	std::string title = "Splendor";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void SessionsManager::initKeys()
{
	this->supportedKeys.emplace("Esc", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

	std::cout << this->supportedKeys.at("A");
}

void SessionsManager::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys,&this->states));
	
}



void SessionsManager::updateEvents()
{
	
	while (window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
		
	}
}

void SessionsManager::update()
{
	this->updateEvents();

	
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endApplication();
		this->window->close();
	}

}

void SessionsManager::render()
{
	this->window->clear();

if (!this->states.empty())
		this->states.top()->render();
	this->window->display();
}

void SessionsManager::Test1Session()
{
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	while (this->window->isOpen())
	{
		this->updateDt();
		this -> update();
		this->render();
	}
}

