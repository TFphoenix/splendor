#include "GamePieces.h"

uint16_t GamePieces::GetGemTokenCount()
{
	return uGemTokenCount;
}

uint16_t GamePieces::GetNobleCardCount()
{
	return uNobleCardCount;
}

void GamePieces::SetGemTokenCount(uint16_t newGemTokenCount)
{
	uGemTokenCount = newGemTokenCount;
}

void GamePieces::SetNobleCardCount(uint16_t newNobleCardCount)
{
	uNobleCardCount = newNobleCardCount;
}
