#pragma once

#include "Network.h"

class Client : public Network
{
public:
	//CONNECT
	bool Connect(sf::IpAddress ipAddress, int port);
	//SEND
	//RECEIVE
private:
	sf::TcpSocket m_socket;
};

