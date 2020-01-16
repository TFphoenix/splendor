#include <iostream>

//Server
#include <SFML/Network.hpp>

int main()
{

	std::cout << "Server running" << std::endl;
	sf::TcpListener listener1, listener2;
	sf::TcpSocket socket1, socket2;
	sf::Packet packet;
	//bool done = false;
	//std::vector < sf::TcpSocket* > clients;
	//


	listener1.listen(2001);
	listener1.accept(socket1);

	/*listener2.listen(2001);
	listener2.accept(socket2);*/

	packet << "Connected to server";
	socket1.send(packet);


	/*socket2.send(packet);*/

	packet.clear();

	socket1.receive(packet);


	return 0;
}