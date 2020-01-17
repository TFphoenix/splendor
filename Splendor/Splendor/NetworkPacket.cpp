#include "NetworkPacket.h"

void NetworkPacket::SetHandData(std::tuple<std::string, std::string, std::string, std::string> handData)
{
	auto [resourcesString, tokensString, expansionString, nobleString] = handData;
	m_handResources = resourcesString;
	m_handTokens = tokensString;
	m_handExpansions = expansionString;
	m_handNoble = nobleString;
}

sf::Packet& operator<<(sf::Packet& packet, const NetworkPacket& networkPacket)
{
	packet << networkPacket.m_handResources;
	packet << networkPacket.m_handTokens;
	packet << networkPacket.m_handExpansions;
	packet << networkPacket.m_handNoble;
	return packet;
}

sf::Packet& operator>>(sf::Packet& packet, NetworkPacket& networkPacket)
{
	packet >> networkPacket.m_handResources;
	packet >> networkPacket.m_handTokens;
	packet >> networkPacket.m_handExpansions;
	packet >> networkPacket.m_handNoble;
	return packet;
}