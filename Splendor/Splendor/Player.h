#pragma once
#include "Hand.h"

class Player
{
public:
	// Constr.
	Player(std::string&& name);

	// G&S
	std::string GetName() const;
	uint16_t GetPrestigePoints() const;

	// Logic
	void AddPrestigePoints(uint16_t amount);

private:
	std::string m_name;
	uint16_t m_prestigePoints;
	Hand m_hand;
};

