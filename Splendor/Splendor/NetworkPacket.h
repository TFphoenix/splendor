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

	void SetHandData(const std::tuple<std::string, std::string, std::string, std::string>& handData);

	//board
	std::string m_boardNobleDeckString;
	std::string m_boardExpansionsDeckString;
	std::string m_boardTokensString;
	std::string m_boardNobleSlotsString;
	std::string m_boardExpansionsSlotsString;

	void SetBoardData(const std::tuple<std::string, std::string, std::string, std::string, std::string>& boardData);
	
	friend std::ostream& operator <<(std::ostream& out, const NetworkPacket& packet)
	{
		//hand data
		out << packet.m_handResources << " ";
		out << packet.m_handTokens << " ";
		out << packet.m_handExpansions << " ";
		out << packet.m_handNoble << ".";
		//board data
		out << packet.m_boardNobleDeckString << " ";
		out << packet.m_boardExpansionsDeckString << " ";
		out << packet.m_boardTokensString << " ";
		out << packet.m_boardNobleSlotsString << " ";
		out << packet.m_boardExpansionsSlotsString;
		return out;
	}

	friend std::istream& operator >>(std::istream& in, NetworkPacket& packet)
	{
		//hand data
		in >> packet.m_handResources;
		in >> packet.m_handTokens;
		in >> packet.m_handExpansions;
		in >> packet.m_handNoble;
		//board data
		in >> packet.m_boardNobleDeckString;
		in >> packet.m_boardExpansionsDeckString;
		in >> packet.m_boardTokensString;
		in >> packet.m_boardNobleSlotsString;
		in >> packet.m_boardExpansionsSlotsString;
		return in;
	}
};

sf::Packet& operator <<(sf::Packet& packet, const NetworkPacket& networkPacket);

sf::Packet& operator >>(sf::Packet& packet, NetworkPacket& networkPacket);