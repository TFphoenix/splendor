#pragma once

#include "Network.h"
#include <sstream>

class Server : public Network
{
public:
	Server();
	~Server();
public:
	bool Connect(int port);
	//LISTEN
	bool Listen(int port);
	//ACCEPT
	bool Accept(sf::TcpSocket* client);
	//RECEIVE
	bool Receive(sf::Packet packet);
	//SEND
	bool Send(sf::Packet packet);
private:
	sf::TcpListener m_socketListener;
	sf::SocketSelector m_socketSelector;
	std::vector<sf::TcpSocket*> m_connectedClients;

	std::stringstream m_serverStream;
};

