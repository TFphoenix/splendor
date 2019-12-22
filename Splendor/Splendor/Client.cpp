#include "Client.h"

bool Client::Connect(sf::IpAddress ipAddress, int port) {

	const sf::Socket::Status status = m_socket.connect(ipAddress, port);

	if (status == sf::Socket::Done) {
		return true;
	}

	return false;
}

bool Client::Send(sf::Packet packet) {

	const sf::Socket::Status status = m_socket.send(packet);

	if (status == sf::Socket::Done) {
		return true;
	}

	return false;
}

bool Client::Receive(sf::Packet packet) {
	const sf::Socket::Status status = m_socket.send(packet);

	if (status == sf::Socket::Done) {
		return true;
	}

	return false;
}
