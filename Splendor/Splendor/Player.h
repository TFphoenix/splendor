#pragma once
#include "Hand.h"

class Player
{
public:
	enum class Type
	{
		User,
		Computer
	};

public:
	// Constr.
	Player(std::string&& name, Type type = Type::User);

	// G&S
	std::string GetName() const;
	Type GetType() const;
	uint16_t GetPrestigePoints() const;
	Hand GetHand() const;

	// Logic
	void AddPrestigePoints(uint16_t amount);

private:
	std::string m_name;
	Type m_type;
	uint16_t m_prestigePoints;
	Hand m_hand;
};

