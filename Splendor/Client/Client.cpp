#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

std::string ipAddress = "84.232.140.47";

int main()
{

	sf::IpAddress ip = sf::IpAddress("192.168.221.245");
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

	return 0;
}