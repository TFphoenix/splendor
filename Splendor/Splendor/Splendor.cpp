#include "SessionsManager.h"

#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include "Network.h"

int StartServer()
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
	return 0;
}

int main() {
	
	SessionsManager SplendorSession;
	SplendorSession.MainMenuSession();

	Network network;

	return 0;
}
