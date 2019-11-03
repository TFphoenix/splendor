#pragma once
#include <optional>
#include <cstdint>

class ICard
{
public:
	virtual ~ICard() = 0;

private:
	std::optional<uint16_t> m_prestigePoints;
	bool m_isFaceUp;
};

