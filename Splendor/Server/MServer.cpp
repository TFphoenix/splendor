#include <iostream>
#include <sstream>

#include <WS2tcpip.h>

int main() {
	//int multipleConnectionServer() {

	int port = 13010; // Listening port # on the server

	// ** initialize winsock
	WSADATA serverSocketData;	//the call to winsock startup will fill this; we need this for the initialization of the socket
	WORD version = MAKEWORD(2, 2);	//using version 2.2

	int winSocketOk = WSAStartup(version, &serverSocketData);	//needs &, will be modified
	if (winSocketOk != 0) {
		std::cout << "Could not establish connection!" << std::endl;
		return 1;
	}

	// ** create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);	//using the TCP protocol
	if (listening == INVALID_SOCKET) {
		std::cout << "Could not create socket" << std::endl;
		WSACleanup();
		return 2;
	}

	// ** bind an IP address and Port to a socket (the tuple that identifies the connection)
	sockaddr_in hint;
	hint.sin_family = AF_INET;	//using version 4
	hint.sin_port = htons(port);	//because of the little/big endian differences; host to network short (htons)
	hint.sin_addr.S_un.S_addr = INADDR_ANY;	//we want to bind to any address

	//std::string ipAddress = "127.0.0.1";
	//inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	//basically we are binding this port to any address to this socket which we've initialized earlier
	bind(listening, (sockaddr*)&hint, sizeof(hint));	//we need the address of the structure

	// ** tell winsock the socket is for listening
	listen(listening, SOMAXCONN);	//maximum connections we can have

	// ** multiple client server
	fd_set master;
	FD_ZERO(&master);

	FD_SET(listening, &master);	//adds the listening socket to the set

	while (true) {
		//select will destroy the master set so we make a copy of it
		fd_set copy = master;

		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);	//if we get any sockets, the sockets will be in the array copy

		for (int i = 0; i < socketCount; ++i) {
			//a server can either accept a connection or receive a message
			SOCKET socket = copy.fd_array[i];
			if (socket == listening) {

				//accept a connection
				SOCKET client = accept(listening, nullptr, nullptr);
				//add a new connection to the master set of clients
				FD_SET(client, &master);
				//send a welcome message to the connected client
				std::string welcomeMessage = "Welcome to the Splendor Game server!\n";
				send(client, welcomeMessage.c_str(), welcomeMessage.size() + 1, 0);

			} else {

				//receive a message
				char buffer[4096];
				memset(buffer, 0, 4096);

				int bytesReceived = recv(socket, buffer, 4096, 0);
				if (bytesReceived <= 0) {
					std::cout << "Client dropped";
					closesocket(socket);
					FD_CLR(socket, &master);
				} else {

				}
				//send message to other clients and not to the listening socket
				for (size_t i = 0; i < master.fd_count; i++) {
					SOCKET outSocket = master.fd_array[i];
					if (outSocket != listening && outSocket != socket) {
						std::ostringstream ss;
						ss << "SOCKET #" << socket << ": " << buffer << "\n";
						std::string stringOut = ss.str();

						send(outSocket, stringOut.c_str(), stringOut.size() + 1, 0);	//socket buffer can be formatted as a form of ID
					}
				}
			}
		}

		if(socketCount == 0)
		{
			break;
		}
	}

	// ** shut down winsock
	WSACleanup();

	return 0;
}
