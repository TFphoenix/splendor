#include "PregameSetup.h"

PregameSetup::PregameSetup(uint16_t playerCount) :m_playerCount(playerCount)
{
	if (playerCount < 2 || playerCount > 4)
		throw "ERROR: Wrong playerCount (Value must be between 2-4)";

	g_UNobleCardCount = playerCount + 1;
	switch (playerCount)
	{
	case 2:
		g_UGemTokenCount = g_GemTokenCount - 3;
		break;
	case 3:
		g_UGemTokenCount = g_GemTokenCount - 2;
		break;
	default:
		g_UGemTokenCount = g_GemTokenCount;
	}
}

uint16_t PregameSetup::GetPlayerCount() const
{
	return m_playerCount;
}
