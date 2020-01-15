#include "SessionsManager.h"

#include "Client.h"
#include "Server.h"

int main() {
	
	SessionsManager SplendorSession;
	SplendorSession.MainMenuSession();

	//Server server = Server();
	//Client client;

	const std::string ip("127.0.0.1");
	int port = 27015;

	sf::IpAddress ipAddress(ip);

	return 0;
}
