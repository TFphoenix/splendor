
#include <iostream>

//CLIENT
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

int main()
{

	std::string ipAddress("172.27.3.50");
	sf::TcpSocket socket;

	std::string clientName("Adi");

	int port = 13010;
	socket.connect(ipAddress, port);

	bool quit = false;
	std::string message;
	sf::Packet packet;

	while (!quit)
	{

		std::cout << ", your message: ";
		std::getline(std::cin, message);
		packet << message;
		socket.send(packet);

		packet.clear();
		message.clear();

		// receive	
		socket.receive(packet);
		packet >> message;
		std::cout << clientName << " " << message << std::endl;

		packet.clear();
		message.clear();

	}

	return 0;
}

/*
sf::IpAddress ip = sf::IpAddress("10.0.0.48");
sf::TcpSocket socket;
sf::Packet packet;
std::string message;

socket.connect(ip, 2001);

socket.receive(packet);
packet >> message;

std::cout << message;
packet.clear();

packet << "client connected adi";
socket.send(packet);
*/