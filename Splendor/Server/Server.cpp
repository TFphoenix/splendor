
#include <iostream>

//Server
#include <SFML/Network.hpp>

int main()
{

	int port = 2000;

	sf::TcpListener listener;
	sf::Packet packet;
	sf::TcpSocket socket;

	std::cout << "Server is running and accepting connections on port " << port << std::endl;

	listener.listen(port);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;

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

		// send
		std::cin >> message;
		packet << message;
		socket.send(packet);

		packet.clear();
		
		// receive	
		socket.receive(packet);
		std::string buffer;
		packet >> buffer;
		std::cout << "The client said: " << buffer << std::endl;
	}

	return 0;
}

/*
std::cout << "Server running" << std::endl;
sf::TcpListener listener1,listener2;
sf::TcpSocket socket1,socket2;
sf::Packet packet;
//bool done = false;
//std::vector < sf::TcpSocket* > clients;
//


listener1.listen(2001);
listener1.accept(socket1);

//listener2.listen(2001);
//listener2.accept(socket2);

packet << "Connected to server";
socket1.send(packet);


//socket2.send(packet);

packet.clear();

socket1.receive(packet);
*/