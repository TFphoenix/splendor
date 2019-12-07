#pragma once
#include "UIPanel.h"
#include "UIText.h"
#include "UIButton.h"

#include <chrono>

class UIInfoPanel :public UIPanel
{
public:
	using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

	struct Timer
	{
		bool running = false;
		TimePoint startTime, currentTime;
		//uint16_t hours = 0;
		//uint16_t minutes = 0;
		//double seconds = 0;

		//void TransferTime()
		//{
		//	minutes = seconds / 60;
		//	seconds = 0;
		//	
		//	if (minutes >= 60)
		//	{
		//		hours = 0;
		//		hours += 1;
		//	}
		//}
	};

public:
	UIInfoPanel(const sf::Vector2f& position = { 0,0 }, const sf::Vector2f& size = { 1024,100 }, bool isActive = true);

	// Info manipulation
	void IncrementTurn();
	void UpdateTime();
	void StartTimer();
	void StopTimer();

	// Events
	bool MenuButtonTriggered() const;

private:
	void UpdateTimeLabel();
	void UpdateTurnLabel();

private:
	static inline const uint16_t s_padding = 10;

private:
	Timer m_timer;
	uint16_t m_turn;
	UIText m_timeTitle, m_timeLabel;
	UIText m_turnTitle, m_turnLabel;
	UIButton* m_menuButton;
};

