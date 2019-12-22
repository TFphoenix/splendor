#pragma once

#include "Network.h"
#include <sstream>

class Server : public Network
{
public:
	//LISTEN
	//ACCEPT
	//RECEIVE
	//SEND
private:
	sf::TcpListener m_socketListener;

	std::stringstream m_serverStream;
};

