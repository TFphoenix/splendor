#pragma once
#include <optional>
#include <cstdint>

class ICard
{
public:
	ICard(uint16_t prestigePoints, bool isFaceUp);

	virtual ~ICard() = 0;

private:
	std::optional<uint16_t> m_prestigePoints;
	bool m_isFaceUp;
};

