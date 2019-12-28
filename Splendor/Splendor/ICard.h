#pragma once
#include <cstdint>
#include <unordered_map>

#include "IToken.h"

class ICard
{
public:
	using GemType = IToken::Type;
	using GemsMap = std::unordered_map<GemType, uint16_t>;

public:
	// Constr. & Destr.
	ICard(uint16_t id, bool isFaceUp, uint16_t prestigePoints = 0);
	virtual ~ICard() = 0;

	// G&S
	uint16_t GetId() const;
	bool GetIsFaceUp() const;
	void SetIsFaceUp(bool isFaceUp);
	uint16_t GetPrestigePoints();

protected:
	// G&S
	void SetPrestigePoints(uint16_t prestigePoints);

protected:
	// Logic
	uint16_t m_prestigePoints;
	bool m_isFaceUp;

	// DAO
	uint16_t m_id;
};

