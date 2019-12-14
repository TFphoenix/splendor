#include <iostream>

// *** IMPORTANT *** Linker->Input->Additional Dependencies->
//add sfml-network-d.lib
//
//

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network.hpp>

const unsigned short PORT = 13010;
const std::string IPADDRESS("127.0.0.1");

int main() {
	sf::TcpSocket socket;

	char buffer[4096];
	std::size_t bytesReceived;

	char connectionType;
	char mode;

	std::string text = "Connected to: ";

	std::cout << "s > server" << std::endl;
	std::cout << "c > client" << std::endl;
	std::cout << "> ";
	
	std::cin >> connectionType;

	if (connectionType == 's') {
		//sf::TcpListener listener;
		//listener.listen(PORT);
		//listener.accept(socket);
		text += "server.";
		std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
	} else {
		socket.connect(IPADDRESS, PORT);
		text += "client.";
	}

	socket.send(text.c_str(), text.length() + 1);

	socket.receive(buffer, sizeof(buffer), bytesReceived);

	std::cout << buffer << std::endl;

	system("pause");
	return 0;
}