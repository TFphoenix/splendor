#include "UILeaderboardSession.h"

#define range  60.0f
float startY = 110.f;
float margin = 0.3;

UILeaderboardSession::UILeaderboardSession(const sf::Vector2u& windowSize) :
	m_gameModePanel("", UIOptionsPanel::Type::Radio,
		sf::Vector2f(50.0f, 0.2f * windowSize.y + 30.0f),
		sf::Vector2f(windowSize.x - 50.0f, 0.15f * windowSize.y))
{
	// Title Background
	m_titleBackground.setPosition(0, 0);
	m_titleBackground.setSize(sf::Vector2f(windowSize.x, 0.2f * windowSize.y));
	m_titleBackground.setFillColor(UIColors::DarkYellow);

	// Title
	m_title.setString("LeaderBoard");
	m_title.setCharacterSize(80);
	m_title.setFillColor(UIColors::NeutralWhite);
	m_title.setPosition(windowSize.x / 2.0f, 0.2f * windowSize.y / 2.0f);
	m_title.AlignText(UIText::TextAlign::mid_center);

	//Button
	sf::RectangleShape button({ 300,80 });

	// Main Menu Button
	button.setPosition(windowSize.x - 350.0f, windowSize.y - 130.0f);
	m_backToMenuButton = new UIButton(button);
	m_backToMenuButton->ChangeText("Main Menu");

	//Text
	m_labelText1 = new UIText(sf::Vector2f(150.0f, 0.3 * windowSize.y + 110.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "1st Place", 60);
	m_labelText1->setFillColor(UIColors::GoldYellow);
	m_labelText1->setOutlineThickness(3.0f);
	m_labelText1->AlignText(UIText::TextAlign::mid_center);
	m_labelText2 = new UIText(sf::Vector2f(150.0f, 0.35 * windowSize.y + 170.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "2nd Place", 60);
	m_labelText2->setFillColor(UIColors::GoldYellow);
	m_labelText2->setOutlineThickness(3.0f);
	m_labelText2->AlignText(UIText::TextAlign::mid_center);
	m_labelText3 = new UIText(sf::Vector2f(150.0f, 0.4 * windowSize.y + 220.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "3rd Place", 60);
	m_labelText3->setFillColor(UIColors::GoldYellow);
	m_labelText3->setOutlineThickness(3.0f);
	m_labelText3->AlignText(UIText::TextAlign::mid_center);
	m_labelText4 = new UIText(sf::Vector2f(150.0f, 0.45 * windowSize.y + 280.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "4th Place", 60);
	m_labelText4->setFillColor(UIColors::GoldYellow);
	m_labelText4->setOutlineThickness(3.0f);
	m_labelText4->AlignText(UIText::TextAlign::mid_center);
	m_labelText5 = new UIText(sf::Vector2f(150.0f, 0.5 * windowSize.y + 340.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "5th Place", 60);
	m_labelText5->setFillColor(UIColors::GoldYellow);
	m_labelText5->setOutlineThickness(3.0f);
	m_labelText5->AlignText(UIText::TextAlign::mid_center);

	m_nameText = new UIText(sf::Vector2f(0.3 * windowSize.x + 150.0f, 0.3 * windowSize.y + 30.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "Name", 60);
	m_nameText->setFillColor(UIColors::GoldYellow);
	m_nameText->setOutlineThickness(3.0f);
	m_nameText->AlignText(UIText::TextAlign::mid_center);
	m_numberOfWins = new UIText(sf::Vector2f(0.4 * windowSize.x + 350.0f, 0.3 * windowSize.y + 30.0f), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "Win Record", 60);
	m_numberOfWins->setFillColor(UIColors::GoldYellow);
	m_numberOfWins->setOutlineThickness(3.0f);
	m_numberOfWins->AlignText(UIText::TextAlign::mid_center);

	m_labelTextDrawableVector.push_back(m_labelText1);
	m_labelTextDrawableVector.push_back(m_labelText2);
	m_labelTextDrawableVector.push_back(m_labelText3);
	m_labelTextDrawableVector.push_back(m_labelText4);
	m_labelTextDrawableVector.push_back(m_labelText5);
	m_labelTextDrawableVector.push_back(m_nameText);
	m_labelTextDrawableVector.push_back(m_numberOfWins);
}

UILeaderboardSession::~UILeaderboardSession()
{
	delete m_backToMenuButton;
}

void UILeaderboardSession::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_titleBackground);
	target.draw(m_title);
	for (const auto& drawable : m_labelTextDrawableVector)
	{
		target.draw(*drawable);
	}
	target.draw(m_gameModePanel);
	target.draw(*m_backToMenuButton);
	for (const auto& drawable : m_playerNameDrawableVector)
	{
		target.draw(*drawable);
	}
	for (const auto& drawable : m_playerNumberOfWinsDrawableVector)
	{
		target.draw(*drawable);
	}

}

void UILeaderboardSession::PassEvent(const sf::Event& event)
{
	m_backToMenuButton->HandleEvent(event);

}

UILeaderboardSession::Events UILeaderboardSession::GetEvent() const
{
	if (m_backToMenuButton->GetState() == UIButton::State::Release)
	{
		return Events::MainMenu;
	}
	return Events::None;
}

bool SortBySec(const std::pair<std::string, uint16_t>& a, const std::pair<std::string, uint16_t>& b)
{

	return (a.second > b.second);

}

void UILeaderboardSession::LoadFromFile()
{

	std::ifstream readFile(s_leaderboardFile);
	std::string name;
	uint16_t number;
	while (readFile >> name >> number)
	{
		s_leaderboard.push_back(std::make_pair(name, number));
	}

	std::sort(s_leaderboard.begin(), s_leaderboard.end(), SortBySec);

}

void UILeaderboardSession::LoadLeaderboard(const sf::Vector2u& windowSize)
{


	for (uint16_t playerIt = 0; playerIt < s_top5; ++playerIt)
	{
		auto& [name, wins] = s_leaderboard[playerIt];

		s_playerName = new UIText(sf::Vector2f(0.3 * windowSize.x + 150.0f, margin * windowSize.y + startY), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, name, 60);
		s_playerName->setFillColor(UIColors::OpaqueWhite);
		s_playerName->setOutlineThickness(3.0f);
		s_playerName->AlignText(UIText::TextAlign::mid_center);

		m_playerNameDrawableVector.push_back(s_playerName);
		startY += range;
		margin += 0.05f;
	}

	startY = 110.f;
	margin = 0.3;

	for (uint16_t playerIt = 0; playerIt < s_top5; ++playerIt)
	{
		auto& [name, wins] = s_leaderboard[playerIt];

		s_playerWins = new UIText(sf::Vector2f(0.4 * windowSize.x + 350.0f, margin * windowSize.y + startY), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, std::to_string(wins), 60);
		s_playerWins->setFillColor(UIColors::OpaqueWhite);
		s_playerWins->setOutlineThickness(3.0f);
		s_playerWins->AlignText(UIText::TextAlign::mid_center);

		m_playerNumberOfWinsDrawableVector.push_back(s_playerWins);
		startY += range;
		margin += 0.05f;
	}
}

