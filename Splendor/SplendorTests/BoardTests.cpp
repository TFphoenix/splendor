#include "pch.h"
#include "CppUnitTest.h"

#include "Board.h"

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

		TEST_METHOD(CheckTokenDataSize)
		{
			Board board;
			const std::unordered_map<IToken::Type, uint16_t> tokenData = board.GetTokensData();

			Assert::IsTrue(tokenData.size() == numberOfTokens, L"Number of tokens is not equal to 5!");
		}

		TEST_METHOD(CheckTokenDataElements)
		{
			Board board;
			const std::unordered_map<IToken::Type, uint16_t> tokenData = board.GetTokensData();

			int tokens[5] = { 5, 0, 1, 2, 3 };	//Gold, BlackOnyx, GreenEmerald, WhiteDiamond, BlueSapphire

			int counter = 0;
			for (const auto token : tokenData) {
				IToken::Type type = token.first;
				const int enumNumber = static_cast<int>(type);
				if(enumNumber != tokens[counter++])
				{
					Assert::Fail(L"Tokens were not loaded in order!");
				}
			}
		}

	};
}
