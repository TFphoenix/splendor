#include "pch.h"
#include "CppUnitTest.h"

#include "PregameSetup.h"

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
		
	};
}