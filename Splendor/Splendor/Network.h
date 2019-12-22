#pragma once

#include <SFML/Network.hpp>
#include <SFML/Network/TcpSocket.hpp>

class Network
{
public:

	sf::IpAddress m_address;
	int m_port;

	char* m_buffer;
	int m_bytesReceived;

	std::string m_message;

private:

};