#include "Server.h"
#include <iostream>

Server::Server() {
	m_socketSelector.add(m_socketListener);
}

Server::~Server() {

}

bool Server::Connect(int port) {

	const float timeOut = 10.f;

	if (m_socketSelector.wait(sf::seconds(timeOut))) {

		if (m_socketSelector.isReady(m_socketListener)) {

			sf::TcpSocket* client = new sf::TcpSocket;

			if (m_socketListener.accept(*client) == sf::Socket::Done) {
				// Add the new client to the clients list
				m_connectedClients.push_back(client);
				// Add the new client to the selector so that we will
				// be notified when he sends something
				m_socketSelector.add(*client);

			} else {
				// Error, we won't get a new connection, delete the socket
				delete client;
			}
		}

	} else {
		for (std::vector<sf::TcpSocket*>::iterator it = m_connectedClients.begin(); it != m_connectedClients.end(); ++it) {
			sf::TcpSocket& client = **it;
			if (m_socketSelector.isReady(client)) {
				// The client has sent some data, we can receive it
				sf::Packet packet;
				if (client.receive(packet) == sf::Socket::Done) {

				}
			}
		}
	}
}

bool Server::Listen(int port) {

	const sf::Socket::Status status = m_socketListener.listen(port);

	if (status == sf::Socket::Done) {
		return true;
	}

	return false;
}

bool Server::Accept(sf::TcpSocket* client) {

	const sf::Socket::Status status = m_socketListener.accept(*client);

	if (status == sf::Socket::Done) {

		std::cout
			<< "Client has connected from "
			<< client->getRemoteAddress() << " on port " << client->getRemotePort()
			<< std::endl;

		m_socketSelector.add(*client);
		m_connectedClients.push_back(client);

		return true;
	}

	return false;
}

bool Server::Receive(sf::Packet packet) {

}

bool Server::Send(sf::Packet packet) {

}
