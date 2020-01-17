#include "pch.h"
#include "Deck.h"

#include "Board.h"
#include "CppUnitTest.h"
#include "GamePieces.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SplendorTests
{
	TEST_CLASS(DeckTests)
	{
	public:
		TEST_METHOD(ExpansionL1DeckInitialization) {
			const Deck<ExpansionCard, 1> m_expansionL1Deck;
			Assert::IsTrue(m_expansionL1Deck.GetNumberOfCards() == GamePieces::s_L1ExpansionCardCount);
		}
		TEST_METHOD(ExpansionL2DeckInitialization) {
			const Deck<ExpansionCard, 2> m_expansionL2Deck;
			Assert::IsTrue(m_expansionL2Deck.GetNumberOfCards() == GamePieces::s_L2ExpansionCardCount);
		}

		TEST_METHOD(ExpansionL3DeckInitialization) {
			const Deck<ExpansionCard, 3> m_expansionL3Deck;
			Assert::IsTrue(m_expansionL3Deck.GetNumberOfCards() == GamePieces::s_L3ExpansionCardCount);
		}

		TEST_METHOD(NobleDeckInitialization) {
			const Deck<NobleCard> m_nobleDeck;
			Assert::IsTrue(m_nobleDeck.GetNumberOfCards() == GamePieces::s_NobleCardCount);
		}

		TEST_METHOD(UndefinitedDeckInitialization) {

			Assert::ExpectException<std::invalid_argument>([]() {const Deck<ExpansionCard, NULL> deck; });
		}

		
	};
}