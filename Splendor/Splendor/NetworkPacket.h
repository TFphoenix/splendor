#pragma once

#include "Board.h"
#include "Hand.h"
#include <SFML/Network/Packet.hpp>

class NetworkPacket
{
	
public:
	//hand
	std::string m_handResources;
	std::string m_handTokens;
	std::string m_handExpansions;
	std::string m_handNoble;
	
	void SetHandData(std::tuple<std::string, std::string, std::string, std::string> handData);

	friend std::ostream& operator <<(std::ostream& out, const NetworkPacket& c)
	{
		out << c.m_handResources << " ";
		out << c.m_handTokens << " ";
		out << c.m_handExpansions << " ";
		out << c.m_handNoble;
		return out;
	}

	friend std::istream& operator >>(std::istream& in, NetworkPacket& c)
	{
		in >> c.m_handResources;
		in >> c.m_handTokens;
		in >> c.m_handExpansions;
		in >> c.m_handNoble;
		return in;
	}
};

sf::Packet& operator <<(sf::Packet& packet, const NetworkPacket& networkPacket);

sf::Packet& operator >>(sf::Packet& packet, NetworkPacket& networkPacket);