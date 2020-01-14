#include "UIGameSession.h"
#include "UISelectedCard.h"

#include <iostream>

UIGameSession::UIGameSession(const sf::Vector2u& windowSize, const PregameSetup& pregameSetup, std::vector<Player>* pPlayers, Board* pBoard, std::reference_wrapper<Player>& rActivePlayer) :
	// instantiate Logic
	p_board(pBoard),
	r_activePlayer(rActivePlayer),
	// instantiate UI panels
	m_infoPanel(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, windowSize.y * 0.05)),
	m_playersPanel(pPlayers, sf::Vector2f(0, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.95)),
	m_tokensPanel(sf::Vector2f(windowSize.x * 0.3, windowSize.y * 0.05), sf::Vector2f(0.1 * windowSize.x, windowSize.y * 0.95)),
	m_noblesPanel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.05), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.26)),
	m_expansionsL3Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.31), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL2Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.54), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_expansionsL1Panel(5, sf::Vector2f(windowSize.x * 0.4, windowSize.y * 0.77), sf::Vector2f(windowSize.x * 0.6, windowSize.y * 0.23)),
	m_handPanel(static_cast<sf::Vector2f>(windowSize), false),
	// instantiate Pregame Set-up
	m_pregameSetup(pregameSetup)
{
	// Instantiate UI Card Rows
	m_noblesPanel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::Noble), 0, true);
	m_noblesPanel.ReverseDrawOrder();
	m_expansionsL3Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL3), 3);
	m_expansionsL3Panel.ReverseDrawOrder();
	m_expansionsL2Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL2), 2);
	m_expansionsL2Panel.ReverseDrawOrder();
	m_expansionsL1Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL1), 1);
	m_expansionsL1Panel.ReverseDrawOrder();
	m_expansionPanels.emplace_back(std::ref(m_expansionsL3Panel));
	m_expansionPanels.emplace_back(std::ref(m_expansionsL2Panel));
	m_expansionPanels.emplace_back(std::ref(m_expansionsL1Panel));

	// Populate panel vector
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_infoPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_playersPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_tokensPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL1Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL2Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_expansionsL3Panel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_noblesPanel));
	m_panels.push_back(dynamic_cast<UIPanel*>(&m_handPanel));

}

void UIGameSession::StartGame()
{
	m_infoPanel.StartTimer();
}

void UIGameSession::StopGame()
{
	m_infoPanel.StopTimer();
}

void UIGameSession::UpdateGame()
{
	// Info
	m_infoPanel.UpdateTime();

	// Tokens Panel
	m_tokensPanel.UpdateTokens(p_board->GetTokensData());
	if (m_tokensPanel.GetHasPicked())
	{
		m_tokensPanel.SetHasPicked(false);
		std::for_each(m_expansionPanels.begin(), m_expansionPanels.end(), [](std::reference_wrapper<UICardsRowPanel>& panel) {panel.get().NumbAll(); });
	}

	// Card Panels
	std::optional<std::pair<UICard*, UICard::State>> pickedCard;
	for (auto& expansionPanel : m_expansionPanels)
	{
		if (pickedCard.has_value())
			continue;
		pickedCard = expansionPanel.get().CheckForPickedCard();
	}
	if (pickedCard.has_value())
	{
		ExpansionCard pickedCardLogicPiece(static_cast<ExpansionCard::Level>(static_cast<uint16_t>(pickedCard.value().first->GetType())), pickedCard.value().first->GetID());
		switch (pickedCard.value().second)
		{
		case UICard::State::LeftRelease:// Buy Card
			std::cout << "Picked card LEFT CLICK\n";
			try
			{
				p_board->ReturnTokens(r_activePlayer.get().GetHand().BuyExpansionCard(std::move(pickedCardLogicPiece)));
				m_tokensPanel.SyncTokens(p_board->GetTokensData());
				pickedCard->first->Deactivate();
				m_tokensPanel.NumbAll();
				std::for_each(m_expansionPanels.begin(), m_expansionPanels.end(), [](std::reference_wrapper<UICardsRowPanel>& panel) {panel.get().NumbAll(); });
			}
			catch (std::length_error & exception)
			{
				// Not enough resources
				std::cout << exception.what() << "\n";
				pickedCard->first->TriggerWarning();
			}
			break;
		case UICard::State::RightRelease:// Hold Card
			std::cout << "Picked card RIGHT CLICK\n";
			try {
				// Transfer card to hand
				r_activePlayer.get().GetHand().AddExpansionCard(std::move(pickedCardLogicPiece));

				// Deactivate UI
				pickedCard->first->Deactivate();
				m_tokensPanel.NumbAll();
				std::for_each(m_expansionPanels.begin(), m_expansionPanels.end(), [](std::reference_wrapper<UICardsRowPanel>& panel) {panel.get().NumbAll(); });
			}
			catch (std::out_of_range & exception)
			{
				// Hand Full
				std::cout << exception.what() << "\n";
				pickedCard->first->TriggerWarning();
			}
			break;
		default:
			break;
		}
		std::cout << "\n";
	}

	// Hand Panel
	const auto triggeredPanel = m_playersPanel.GetIfTriggered();
	if (triggeredPanel != nullptr)
	{
		std::for_each(m_panels.begin(), m_panels.end() - 1, [](UIPanel* panel) {panel->SetInteractable(false); });
		m_handPanel.SetUpHand(*triggeredPanel);
		m_handPanel.SetActive(true);
	}
	if (m_handPanel.CheckForClose())
	{
		std::for_each(m_panels.begin(), m_panels.end() - 1, [](UIPanel* panel) {panel->SetInteractable(true); });
	}

}

void UIGameSession::NextTurn()
{
	// UI Logic
	m_infoPanel.IncrementTurn();
	m_playersPanel.PointToNextPlayer();
	m_tokensPanel.UnNumb();
	m_expansionsL3Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL3), 3);
	m_expansionsL2Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL2), 2);
	m_expansionsL1Panel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::ExpansionL1), 1);
	std::cout << r_activePlayer.get().GetName() << "\n";

	// Validate Active Player Changes
	// Nobles
	const auto wonNoble = m_noblesPanel.CheckForWonNoble(r_activePlayer.get().GetHand().GetResourcesData());
	if (wonNoble.has_value())
	{
		m_noblesPanel.SetCardsData(p_board->GetCardSlotsData(CardDAO::Type::Noble), 0, true);
		std::cout << "WON NOBLE\n";
	}
	// Tokens
	auto& pickedTokens = m_tokensPanel.ExtractPickedTokens();
	for (auto& token : pickedTokens)
	{
		if (token.has_value())
		{
			r_activePlayer.get().GetHand().AddToken(token.value());
			p_board->TakeToken(token.value());
			token.reset();
		}
	}

}

void UIGameSession::SetActivePlayer(std::reference_wrapper<Player> activePlayerReference)
{
	r_activePlayer = activePlayerReference;
}

void UIGameSession::PassEvent(const sf::Event& event)
{
	// iterate panel vector and handle events
	std::for_each(m_panels.begin(), m_panels.end(), [&event](UIPanel* panel)
	{
		panel->HandleEvent(event);
	});
}

UIGameSession::Events UIGameSession::GetEvent() const
{
	// Info Panel
	if (m_infoPanel.MenuButtonTriggered())
		return Events::MenuButton;
	if (m_infoPanel.PassButtonTriggered())
		return Events::PassButton;
	return Events::None;
}

void UIGameSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// iterate panel vector and draw panels
	std::for_each(m_panels.begin(), m_panels.end(), [&target](UIPanel* panel)
		{
			target.draw(*panel);
		});
	// re-draw selected card on top of all drawables
	if (UISelectedCard::Get().first != nullptr)
	{
		target.draw(*UISelectedCard::Get().first);
	}
	// draw selected card text
	if (UISelectedCard::Get().second != nullptr)
	{
		target.draw(*UISelectedCard::Get().second);
	}
}
