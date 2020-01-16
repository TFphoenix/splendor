
#include <iostream>

//CLIENT
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

std::string ipAddress = "84.232.140.47";

int main()
{

	std::string ipAddress("169.254.161.225");
	sf::TcpSocket socket;
	sf::Packet packet;
	
	socket.connect(ipAddress, 2000);

	std::string message;
	char command;
	
	while (true)
	{
		std::cout << "command >";
		std::cin >> command;
		if (command == 'x')
		{
			break;
		}

		std::cin >> message;
		packet << message;
		socket.send(packet);

		packet.clear();

		// receive	
		socket.receive(packet);
		std::string buffer;
		packet >> buffer;
		std::cout << "The server said: " << buffer << std::endl;
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