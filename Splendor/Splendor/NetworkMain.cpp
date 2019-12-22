#include <iostream>

#include "Client.h"
#include "Server.h"

void menu() {
	std::cout << "s > server" << std::endl;
	std::cout << "c > client" << std::endl;
	std::cout << "> ";
}

int test() {

	sf::IpAddress ipAddress("127.0.0.1");
	int port = 27015;

	Server server;
	Client client;

	sf::TcpSocket socket;

	char connectionType;
	menu();
	std::cin >> connectionType;

	if (connectionType == 's') {
		
		sf::TcpListener listener;
		listener.listen(port);
		// Wait for a connection
		sf::TcpSocket socket;
		listener.accept(socket);
		std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
		// Receive a message from the client
		char buffer[1024];
		std::size_t received = 0;
		socket.receive(buffer, sizeof(buffer), received);
		std::cout << "The client said: " << buffer << std::endl;
		// Send an answer
		std::string message = "Welcome, client";
		socket.send(message.c_str(), message.size() + 1);
		
	} else if (connectionType == 'c') {
		
		sf::TcpSocket socket;
		socket.connect(ipAddress, 55001);
		// Send a message to the connected host
		std::string message = "Hi, I am a client";
		socket.send(message.c_str(), message.size() + 1);
		// Receive an answer from the server
		char buffer[1024];
		std::size_t received = 0;
		socket.receive(buffer, sizeof(buffer), received);
		std::cout << "The server said: " << buffer << std::endl;

	}

	system("pause");
	return 0;
}