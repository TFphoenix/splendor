#include "PregameSetup.h"

PregameSetup::PregameSetup(uint16_t playerCount) :m_playerCount(playerCount)
{
	if (playerCount < 2 || playerCount > 4)
		throw "ERROR: Wrong playerCount (Value must be between 2-4)";

	GamePieces::SetNobleCardCount(playerCount + 1);
	switch (playerCount)
	{
	case 2:
		GamePieces::SetGemTokenCount(GamePieces::s_GemTokenCount - 3);
		break;
	case 3:
		GamePieces::SetGemTokenCount(GamePieces::s_GemTokenCount - 2);
		break;
	default:
		GamePieces::SetGemTokenCount(GamePieces::s_GemTokenCount);
	}
}

uint16_t PregameSetup::GetPlayerCount() const
{
	return m_playerCount;
}
