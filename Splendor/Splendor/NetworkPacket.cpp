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
	auto& [tokensString, nobleSlotsString, expansionL1SlotsString, expansionL2SlotsString, expansionL3SlotsString] = boardData;
	m_boardTokensString = tokensString;
	m_boardNobleSlotsString = nobleSlotsString;
	m_boardExpansionL1SlotsString = expansionL1SlotsString;
	m_boardExpansionL2SlotsString = expansionL2SlotsString;
	m_boardExpansionL3SlotsString = expansionL3SlotsString;
}

void NetworkPacket::SetDecksData(const std::tuple<std::string, std::string, std::string, std::string>& decksData)
{
	auto& [nobleDeckString, expansionL1DeckString, expansionL2DeckString, expansionL3DeckString] = decksData;
	m_boardNobleDeckString = nobleDeckString;
	m_boardExpansionL1DeckString = expansionL1DeckString;
	m_boardExpansionL2DeckString = expansionL2DeckString;
	m_boardExpansionL3DeckString = expansionL3DeckString;
}

void NetworkPacket::ClearData()
{
	// Hand
	m_handResources = "";
	m_handTokens = "";
	m_handExpansions = "";
	m_handNoble = "";

	// Board
	m_boardTokensString = "";
	m_boardNobleSlotsString = "";
	m_boardExpansionL1SlotsString = "";
	m_boardExpansionL2SlotsString = "";
	m_boardExpansionL3SlotsString = "";

	// Decks
	m_boardNobleDeckString = "";
	m_boardExpansionL1DeckString = "";
	m_boardExpansionL2DeckString = "";
	m_boardExpansionL3DeckString = "";
}

sf::Packet& operator<<(sf::Packet& packet, const NetworkPacket& networkPacket)
{
	//hand data
	packet << networkPacket.m_handResources;
	packet << networkPacket.m_handTokens;
	packet << networkPacket.m_handExpansions;
	packet << networkPacket.m_handNoble;
	//board data
	packet << networkPacket.m_boardTokensString;
	packet << networkPacket.m_boardNobleSlotsString;
	packet << networkPacket.m_boardExpansionL1SlotsString;
	packet << networkPacket.m_boardExpansionL2SlotsString;
	packet << networkPacket.m_boardExpansionL3SlotsString;
	//decks data
	packet << networkPacket.m_boardNobleDeckString;
	packet << networkPacket.m_boardExpansionL1DeckString;
	packet << networkPacket.m_boardExpansionL2DeckString;
	packet << networkPacket.m_boardExpansionL3DeckString;

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
	packet >> networkPacket.m_boardTokensString;
	packet >> networkPacket.m_boardNobleSlotsString;
	packet >> networkPacket.m_boardExpansionL1SlotsString;
	packet >> networkPacket.m_boardExpansionL2SlotsString;
	packet >> networkPacket.m_boardExpansionL3SlotsString;
	//decks data
	packet >> networkPacket.m_boardNobleDeckString;
	packet >> networkPacket.m_boardExpansionL1DeckString;
	packet >> networkPacket.m_boardExpansionL2DeckString;
	packet >> networkPacket.m_boardExpansionL3DeckString;
	return packet;
}