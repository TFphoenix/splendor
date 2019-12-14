#include <iostream>

// *** IMPORTANT *** Linker->Input->Additional Dependencies->
//add sfml-network-s-d.lib
//add ws2_32.lib

#include <SFML/Network.hpp>

const unsigned short PORT = 13010;
const std::string IPADDRESS("127.0.0.1");

int udp() {
	sf::UdpSocket socket;

	char buffer[4096];
	std::size_t bytesReceived;

	char connectionType;

	std::map<unsigned short, sf::IpAddress> computerID;

	std::string text = "Connected to: ";

	std::cout << "s > server" << std::endl;
	std::cout << "c > client" << std::endl;
	std::cout << "> ";

	std::cin >> connectionType;

	unsigned short portNumber;
	std::cout << "Enter port number: ";
	std::cin >> portNumber;

	socket.bind(portNumber);

	if (connectionType == 's') {
		char answer = 'b';
		do {
			sf::IpAddress rIp;
			unsigned short portNo;
			socket.receive(buffer, sizeof(buffer), bytesReceived, rIp, portNo);	//because we don't know where we are connecting from

			if (bytesReceived > 0) {
				computerID[portNo] = rIp;	
			}
			std::cout << "Answer > ";
			std::cin >> answer;

		} while (answer != 'a');

	} else {

		std::string sIp = "84.232.140.47";
		sf::IpAddress sendIp(sIp);
		socket.send(text.c_str(), text.length() + 1, sendIp, 2000);

	}

	bool done = false;

	while (!done) {
		if (connectionType == 's') {

			std::getline(std::cin, text);
			std::map<unsigned short, sf::IpAddress>::iterator tempIterator;
			for (tempIterator = computerID.begin(); tempIterator != computerID.end(); ++tempIterator) {
				socket.send(text.c_str(), text.length() + 1, tempIterator->second, tempIterator->first);
			}

		} else {
			
			sf::IpAddress tempIp;
			unsigned short tempPort;
			socket.receive(buffer, sizeof(buffer), bytesReceived, tempIp, tempPort);
			if (bytesReceived > 0)	//we don't want to change client to send mode unless the server actually sent something
			{
				std::cout << "Received: " << buffer << std::endl;
			}
			
		}

	}

	return 0;
}

int tcp() {
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
		sf::TcpListener listener;
		listener.listen(PORT);
		listener.accept(socket);
		text += "server.";
		std::cout << "New client connected: " <<
			socket.getRemoteAddress() <<
			" on port " <<
			socket.getRemotePort() <<
			std::endl;
		mode = 's';	//send mode
	} else {
		socket.connect(IPADDRESS, PORT);
		text += "client.";
		mode = 'r';	//receive mode
	}

	socket.send(text.c_str(), text.length() + 1);

	socket.receive(buffer, sizeof(buffer), bytesReceived);

	std::cout << buffer << std::endl;

	bool done = false;

	while (!done) {
		if (mode == 's') {

			std::getline(std::cin, text);
			socket.send(text.c_str(), text.length() + 1);
			mode = 'r';

		} else if (mode == 'r') {
			socket.receive(buffer, sizeof(buffer), bytesReceived);
			if (bytesReceived > 0)	//we don't want to change client to send mode unless the server actually sent something
			{
				std::cout << "Received: " << buffer << std::endl;
				mode = 's';
			}
		}
	}

	return 0;
}

int main() {

	//udp();
	tcp();

	system("pause");
	return 0;
}