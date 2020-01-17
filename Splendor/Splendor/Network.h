#pragma once

#include <string>

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpListener.hpp>

class Network
{
public:

	int m_port = 13010;
	std::string m_name = "";

	std::string m_message = "";
	sf::Packet m_packet;
	sf::IpAddress m_ip = "172.27.3.50";
	sf::TcpListener m_listener;
	sf::TcpSocket m_socket;

public:
	void InitialiseServer();
	void AcceptConnection();
	bool InitialiseClient();

	void SendData();
	void ReceiveData();

};

