#pragma once

#include "Board.h"
#include "Hand.h"
#include <SFML/Network/Packet.hpp>

class NetworkPacket
{

public:
	// Hand
	std::string m_handResources;
	std::string m_handTokens;
	std::string m_handExpansions;
	std::string m_handNoble;

	void SetHandData(const std::tuple<std::string, std::string, std::string, std::string>& handData);

	// Board
	std::string m_boardTokensString;
	std::string m_boardNobleSlotsString;
	std::string m_boardExpansionL1SlotsString;
	std::string m_boardExpansionL2SlotsString;
	std::string m_boardExpansionL3SlotsString;

	void SetBoardData(const std::tuple<std::string, std::string, std::string, std::string, std::string>& boardData);

	// Decks
	std::string m_boardNobleDeckString;
	std::string m_boardExpansionL1DeckString;
	std::string m_boardExpansionL2DeckString;
	std::string m_boardExpansionL3DeckString;

	void SetDecksData(const std::tuple < std::string, std::string, std::string, std::string>& decksData);

	void ClearData();

	friend std::ostream& operator <<(std::ostream& out, const NetworkPacket& packet)
	{
		//hand data
		out << "[Hand Data]\n";
		out << "Resources: " << packet.m_handResources << "\n";
		out << "Tokens: " << packet.m_handTokens << "\n";
		out << "Expansions: " << packet.m_handExpansions << "\n";
		out << "Nobles: " << packet.m_handNoble << "\n";
		//board data
		out << "[Board Data]\n";
		out << "Tokens: " << packet.m_boardTokensString << "\n";
		out << "Nobles: " << packet.m_boardNobleSlotsString << "\n";
		out << "ExpansionsL1: " << packet.m_boardExpansionL1SlotsString << "\n";
		out << "ExpansionsL2: " << packet.m_boardExpansionL2SlotsString << "\n";
		out << "ExpansionsL3: " << packet.m_boardExpansionL3SlotsString << "\n";
		//decks data
		out << "[Decks Data]\n";
		out << "Nobles: " << packet.m_boardNobleDeckString << "\n";
		out << "ExpansionsL1: " << packet.m_boardExpansionL1DeckString << "\n";
		out << "ExpansionsL2: " << packet.m_boardExpansionL2DeckString << "\n";
		out << "ExpansionsL3: " << packet.m_boardExpansionL3DeckString << "\n";

		return out;
	}
};

sf::Packet& operator <<(sf::Packet& packet, const NetworkPacket& networkPacket);

sf::Packet& operator >>(sf::Packet& packet, NetworkPacket& networkPacket);