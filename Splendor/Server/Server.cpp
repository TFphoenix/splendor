#include <iostream>
#include <WS2tcpip.h>	//Winsock header

#pragma comment(lib, "ws2_32.lib")

#define sout std::cout << "\n"
#define lg(x) std::cout << (x)
#define log(x) std::cout << (x) << " "
#define logn(x) std::cout << (x) << "\n"
#define imp(x) std::cout << "---------------" << (x) << "---------------" << "\n"

//int main(){
int singleConnectionServer() {

	int port = 13010;								// Listening port # on the server

	// ** initialize winsock
	WSADATA serverSocketData;	//the call to winsock startup will fill this; we need this for the initialization of the socket
	WORD version = MAKEWORD(2, 2);	//using version 2.2

	int winSocketOk = WSAStartup(version, &serverSocketData);	//needs &, will be modified
	if (winSocketOk != 0) {
		logn("Could not establish connection!");
		return 1;
	}

	// ** create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);	//using the TCP protocol
	if (listening == INVALID_SOCKET) {
		logn("Could not create socket");
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

	// ** wait for a connection
	sockaddr_in client;
	int clientSize = sizeof(client);	//fill in some information about the client and fill in when we get that information
	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);	//the socket we are listening on is bound to port #13010 and whatever IP address
	if (clientSocket == INVALID_SOCKET) {
		logn("Could not initialize client socket");
		closesocket(clientSocket);
		WSACleanup();
		return 3;
	}

	char host[NI_MAXHOST];	//client's remote name; otherwise IP address
	char service[NI_MAXSERV];	//service (port) the client is connected on

	//ZeroMemory(host, NI_MAXHOST);
	//ZeroMemory(service, NI_MAXHOST);
	memset(host, 0, NI_MAXHOST);
	memset(service, 0, NI_MAXSERV);

	//try to lookup the hostname of the client which is connected
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		std::cout << host << " connected on port " << service << std::endl;
	} else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
	}

	// ** close listening socket
	closesocket(listening);	//if you want to connect with more clients this will not be closed, we will keep on listening

	// ** while loop: { accept and echo message back to client }
	char buffer[4096];

	while (true) {
		memset(buffer, 0, 4096);

		//wait for client to send data
		int bytesReceived = recv(clientSocket, buffer, 4096, 0);
		if (bytesReceived == SOCKET_ERROR) {
			logn("Error in recv()");
			break;
		}

		if (bytesReceived == 0) {
			logn("Client disconnected");
			break;
		}

		std::string ack = std::string(buffer, 0, bytesReceived);
		if (ack == "quit") {
			std::cout << "User requested server termination!" << std::endl;
			break;
		}


		std::cout << std::string(buffer, 0, bytesReceived) << std::endl;

		//echo message back to client
		send(clientSocket, buffer, bytesReceived + 1, 0);
	}

	// ** close socket
	closesocket(clientSocket);

	// ** shut down winsock
	WSACleanup();

	return 0;
}