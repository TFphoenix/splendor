#pragma once
#include <cstdint>

class GamePieces
{
public:
	GamePieces() = delete;

	static uint16_t GetGemTokenCount();
	static uint16_t GetNobleCardCount();

	static void SetGemTokenCount(uint16_t newGemTokenCount);
	static void SetNobleCardCount(uint16_t newNobleCardCount);

public:
	// Total Pieces
	static inline const uint16_t s_TokenCount = 40;
	static inline const uint16_t s_GemTokenCount = 7;
	static inline const uint16_t s_GoldTokenCount = 5;

	static inline const uint16_t s_NobleCardCount = 10;

	static inline const uint16_t s_DevelopmentCardCount = 90;
	static inline const uint16_t s_L1DevelopmentCardCount = 40;
	static inline const uint16_t s_L2DevelopmentCardCount = 30;
	static inline const uint16_t s_L3DevelopmentCardCount = 40;

private:
	// Updatable Pieces
	static inline uint16_t uGemTokenCount;
	static inline uint16_t uNobleCardCount;

};