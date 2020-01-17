#include <iostream>

#include "Network.h"

void Network::InitialiseServer()
{
	m_name = "Server";

	m_listener.listen(m_port);
	std::cout << "Server is running and accepting connections on port "
		<< m_listener.getLocalPort() << std::endl;

	std::cout << "Waiting for clients to connect...";
}

void Network::AcceptConnection()
{
	m_listener.accept(m_socket);
	std::cout << "New client connected: " << m_socket.getRemoteAddress() << std::endl;
}

bool Network::InitialiseClient()
{
	m_name = "Client";

	m_socket.connect(m_ip, m_port);

	return true;
}

void Network::SendData(NetworkPacket networkPacket)
{
	m_packet << networkPacket;
	m_socket.send(m_packet);
	m_packet.clear();
}

void Network::ReceiveData(NetworkPacket & networkPacket)
{
	m_socket.receive(m_packet);
	m_packet >> networkPacket;
	m_packet.clear();
}

