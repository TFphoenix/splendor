#pragma once

#include "Board.h"
#include "Hand.h"
#include <SFML/Network/Packet.hpp>

class NetworkPacket : public sf::Packet
{

public:
	Board m_board;
	Hand m_hand;
	NetworkPacket(Board board, Hand hand);

public:
	sf::Uint16 m_age;
	std::string m_name;
	float m_weight;

	NetworkPacket(sf::Uint8 age, std::string name, float weight);

	friend std::ostream& operator <<(std::ostream& out, const NetworkPacket& c)
	{
		return out << c.m_age << " " << c.m_name << " " << c.m_weight;
	}

	friend std::istream& operator >>(std::istream& in, NetworkPacket& c)
	{
		return in >> c.m_age >> c.m_name >> c.m_weight;
	}
};

sf::Packet& operator <<(sf::Packet& packet, const NetworkPacket& networkPacket);

sf::Packet& operator >>(sf::Packet& packet, NetworkPacket& networkPacket);