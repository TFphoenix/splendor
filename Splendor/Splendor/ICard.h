#pragma once
#include <optional>
#include <cstdint>

class ICard
{
public:
	virtual ~ICard() = 0;

protected:
	std::optional<uint16_t> m_prestigePoints;
};

