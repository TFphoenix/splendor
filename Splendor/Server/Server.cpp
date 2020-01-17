
#include <iostream>

//SERVER
#include <SFML/Network.hpp>

int main()
{

	int port = 13010;

	sf::TcpListener listener;
	sf::Packet packet;
	sf::TcpSocket socket;

	std::string serverName("Server: ");

	listener.listen(port);
	std::cout << "Server is running and accepting connections on port " << listener.getLocalPort() << " and address: " << std::endl;
	std::cout << "Waiting for clients to connect...";

	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;

	std::string message;
	char command = 'a';

	bool quit = false;
	sf::Mutex globalMutex;

	std::string msgSend;
	std::string oldMsg;

	sf::Packet packetReceive;
	std::string msg;

	//SessionsManager SplendorSession;
	//SplendorSession.MainMenuSession();

	while (!quit)
	{

		// receive	
		socket.receive(packet);
		packet >> message;
		std::cout << "Adi said: " << " " << message << std::endl;

		packet.clear();
		message.clear();

		std::cout << ", your message: ";
		std::getline(std::cin, message);
		packet << message;
		socket.send(packet);

		packet.clear();
		message.clear();

	}

	/*
	while (true)
	{

		//std::cout << "command >";
		//std::cin >> command;
		std::cout << serverName;
		if (command == 'x')
		{
			break;
		}

		// receive
		socket.receive(packet);
		std::string buffer;
		packet >> message;
		std::cout << serverName << " " << message << std::endl;

		// send
		std::getline(std::cin, message);
		packet << message;
		socket.send(packet);

		packet.clear();
		message.clear();
	}
	*/

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