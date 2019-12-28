#pragma once
#include "ICard.h"

class NobleCard :ICard
{
public:
	// Constr.
	NobleCard(
		uint16_t id,
		bool isFaceUp = false);

	// G&S
	GemsMap GetRequirements() const;
	std::string GetName() const;

private:
	std::string m_name;
	GemsMap m_requirements;
};

