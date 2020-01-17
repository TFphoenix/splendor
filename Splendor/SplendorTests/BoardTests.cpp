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

	};
}
