#pragma once

#include <SFML/Network.hpp>

class Network
{
public:
	Network();
	~Network();
public:

	sf::IpAddress m_address;
	int m_port;

	char* m_buffer;
	int m_bytesReceived;

	std::string m_message;

	bool Send(char* message, int message_size);
	bool Receive(char* buffer, int buffer_size, int bytesReceived);
	
private:

};

