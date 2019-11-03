#include "SessionsManager.h"

SessionsManager::SessionsManager()
{
	m_window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

void SessionsManager::MainSession()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		m_window->clear();
		m_window->draw(shape);
		m_window->display();
	}
}
