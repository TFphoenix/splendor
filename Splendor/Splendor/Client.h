#pragma once

#include "Network.h"

class Client : public Network
{
	
public:
	//CONNECT
	bool Connect(sf::IpAddress ipAddress, int port);
	//SEND
	bool Send(sf::Packet packet);
	//RECEIVE
	bool Receive(sf::Packet packet);
private:
	sf::TcpSocket m_socket;
};

