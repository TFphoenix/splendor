#include "NetworkPacket.h"

NetworkPacket::NetworkPacket(sf::Uint8 age, std::string name, float weight)
{
	m_age = age;
	m_name = name;
	m_weight = weight;
}

sf::Packet& operator<<(sf::Packet& packet, const NetworkPacket& networkPacket)
{
	return packet << networkPacket.m_age << networkPacket.m_name << networkPacket.m_weight;
}

sf::Packet& operator>>(sf::Packet& packet, NetworkPacket& networkPacket)
{
	return packet >> networkPacket.m_age >> networkPacket.m_name >> networkPacket.m_weight;
}