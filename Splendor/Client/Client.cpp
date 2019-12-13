#include <iostream>
#include <WS2tcpip.h>	//Winsock header
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {

	std::string ipAddress = "127.0.0.1";			// IP Address of the server
	int port = 13010;								// Listening port # on the server

	// ** initialize winsock
	WSAData clientSocketData;
	WORD version = MAKEWORD(2, 2);

	int winSocketOk = WSAStartup(version, &clientSocketData);

	if (winSocketOk != 0) {
		std::cout << "Could not initialize winsock. Error number: " << winSocketOk << std::endl;
		return 1;
	}

	// ** create socket
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);	//AF = address family
	if (clientSocket == INVALID_SOCKET) {
		std::cout << "Could not initialize socket. Error number: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 2;
	}

	// ** fill in a hint structure
	// tells winsock what server and what port to connect to
	sockaddr_in hint; //int because it's an IPv4 version of this sockaddr data structure
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);	//turns string version 127.0.0.1 into bytes

	// ** connect to a server
	int connectResult = connect(clientSocket, (sockaddr*)&hint, sizeof(hint));
	if (connectResult == SOCKET_ERROR) {
		std::cout << "Can't connect to server. Error number: " << WSAGetLastError << std::endl;
		closesocket(clientSocket);
		WSACleanup();
		return 3;
	}

	// ** while {send and receive data}
	char buffer[4096];
	std::string userInput;

	do {

		// ask for user input
		std::cout << "> ";
		std::getline(std::cin, userInput);

		if (userInput.size() > 0) {	// verify user has typed something

			// send the text
			int sendResult = send(clientSocket, userInput.c_str(), userInput.size() + 1, 0);

			if (sendResult != SOCKET_ERROR) {
				// wait for response
				memset(buffer, 0, 4096);
				int bytesReceived = recv(clientSocket, buffer, 4096, 0);

				if (bytesReceived) {
					std::cout << "SERVER > " << std::string(buffer, 0, bytesReceived) << std::endl;
				}
			}
		}

	} while (userInput.size() > 0);

	// ** shut down winsock
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}