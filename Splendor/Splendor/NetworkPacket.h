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
	std::string m_boardExpansionsSlotsString;

	void SetBoardData(const std::tuple<std::string, std::string, std::string>& boardData);

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
		out << "Hand Data: ";
		out << packet.m_handResources << " ";
		out << packet.m_handTokens << " ";
		out << packet.m_handExpansions << " ";
		out << packet.m_handNoble << "\n";
		//board data
		out << "Board Data: ";
		out << packet.m_boardTokensString << " ";
		out << packet.m_boardNobleSlotsString << " ";
		out << packet.m_boardExpansionsSlotsString << "\n";
		//decks data
		out << "Decks Data: ";
		out << packet.m_boardNobleDeckString << " ";
		out << packet.m_boardExpansionL1DeckString << " ";
		out << packet.m_boardExpansionL2DeckString << " ";
		out << packet.m_boardExpansionL3DeckString << "\n";

		return out;
	}
};

sf::Packet& operator <<(sf::Packet& packet, const NetworkPacket& networkPacket);

sf::Packet& operator >>(sf::Packet& packet, NetworkPacket& networkPacket);