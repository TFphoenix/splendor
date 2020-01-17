#include "pch.h"
#include "Board.h"

#include "CppUnitTest.h"
#include "GamePieces.h"
#include "PregameSetup.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int numberOfTokens = 5;

namespace SplendorTests
{
	TEST_CLASS(BoardTests)
	{
	public:

		TEST_METHOD(InitializeBoard) {
			Board board;
		}

		TEST_METHOD(TokenOverflow) {
			PregameSetup pregameSetup(4, PregameSetup::GameMode::Local, false, false);
			Board board;
			
			uint16_t amount = GamePieces::s_GemTokenCount + 1;
			const auto func = [&board, &amount]()
			{
				while (amount)
				{

					board.TakeToken(IToken::Type::BlackOnyx);
					--amount;
				}
			};

			Assert::ExpectException<std::out_of_range>(func);
		}

		TEST_METHOD(TokenUnderflow) {
			PregameSetup pregameSetup(4, PregameSetup::GameMode::Local, false, false);
			Board board;

			const auto func = [&board]()
			{
				board.ReturnToken(IToken::Type::BlackOnyx);
			};

			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}
