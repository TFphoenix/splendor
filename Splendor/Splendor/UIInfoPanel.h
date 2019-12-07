#pragma once
#include "UIPanel.h"
#include "UIText.h"
#include "UIButton.h"

#include <chrono>

class UIInfoPanel :public UIPanel
{
public:
	using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

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

private:
	static inline const uint16_t s_padding = 10;

private:
	bool m_timerRunning;
	uint16_t m_turn;
	TimePoint m_startTime, m_currentTime;
	UIText m_timeTitle, m_timeLabel;
	UIText m_turnTitle, m_turnLabel;
	UIButton* m_menuButton;
};

