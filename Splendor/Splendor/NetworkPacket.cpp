#include "NetworkPacket.h"

void NetworkPacket::SetHandData(const std::tuple<std::string, std::string, std::string, std::string>& handData)
{
	auto& [resourcesString, tokensString, expansionString, nobleString] = handData;
	m_handResources = resourcesString;
	m_handTokens = tokensString;
	m_handExpansions = expansionString;
	m_handNoble = nobleString;
}

void NetworkPacket::SetBoardData(const std::tuple<std::string, std::string, std::string, std::string, std::string>& boardData)
{
	auto& [nobleDeckString, expansionsDeckString, tokensString, nobleSlotsString, expansionsSlotsString] = boardData;
	m_boardNobleDeckString = nobleDeckString;
	m_boardExpansionsDeckString = expansionsDeckString;
	m_boardTokensString = tokensString;
	m_boardNobleSlotsString = nobleSlotsString;
	m_boardExpansionsSlotsString = expansionsSlotsString;
}

sf::Packet& operator<<(sf::Packet& packet, const NetworkPacket& networkPacket)
{
	//hand data
	packet << networkPacket.m_handResources;
	packet << networkPacket.m_handTokens;
	packet << networkPacket.m_handExpansions;
	packet << networkPacket.m_handNoble;
	//board data
	packet << networkPacket.m_boardNobleDeckString;
	packet << networkPacket.m_boardExpansionsDeckString;
	packet << networkPacket.m_boardTokensString;
	packet << networkPacket.m_boardNobleSlotsString;
	packet << networkPacket.m_boardExpansionsSlotsString;
	return packet;
}

sf::Packet& operator>>(sf::Packet& packet, NetworkPacket& networkPacket)
{
	//hand data
	packet >> networkPacket.m_handResources;
	packet >> networkPacket.m_handTokens;
	packet >> networkPacket.m_handExpansions;
	packet >> networkPacket.m_handNoble;
	//board data
	packet >> networkPacket.m_boardNobleDeckString;
	packet >> networkPacket.m_boardExpansionsDeckString;
	packet >> networkPacket.m_boardTokensString;
	packet >> networkPacket.m_boardNobleSlotsString;
	packet >> networkPacket.m_boardExpansionsSlotsString;
	return packet;
}