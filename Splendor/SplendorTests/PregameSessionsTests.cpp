#include "pch.h"
#include "CppUnitTest.h"

#include "PregameSetup.h"
#include "Board.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SplendorTests
{
	TEST_CLASS(PregameSessionsTests)
	{
	public:

		TEST_METHOD(InitializePregameSetupFor3Players)
		{
			const int playerCount = 3;
			const bool withTimer = false;
			const bool withAI = false;
			PregameSetup pregameSetup(playerCount, PregameSetup::GameMode::Local, withTimer, withAI);
		}

		TEST_METHOD(CheckNobleDataFor3Players)
		{
			const int playerCount = 3;
			const int nobleCount = playerCount + 1;
			const bool withTimer = false;
			const bool withAI = false;
			PregameSetup pregameSetup(playerCount, PregameSetup::GameMode::Local, withTimer, withAI);

			const int two = pregameSetup.GetPlayerCount();
			std::cout << two;

			Board board;
			const int numberOfNobleCards = board.GetCardSlotsData(CardDAO::Type::Noble).size();

			Assert::IsTrue(numberOfNobleCards == nobleCount, L"Number of nobles is not equal to player count (3) + 1!");
		}

		TEST_METHOD(CheckTokenDataFor3Players){
			const int playerCount = 3;
			const int tokenCount = playerCount + 1;
			const bool withTimer = false;
			const bool withAI = false;
			PregameSetup pregameSetup(playerCount, PregameSetup::GameMode::Local, withTimer, withAI);

			Board board;
			const int numberOfToken = board.GetTokensData()[IToken::Type::BlueSapphire];
			Assert::IsTrue(numberOfToken == GamePieces::GetGemTokenCount());
			
			
		}
	};
}