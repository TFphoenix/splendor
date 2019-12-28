#include "Player.h"

Player::Player(std::string&& name) :
	m_name(std::move(name)),
	m_prestigePoints(0) {}

std::string Player::GetName() const
{
	return m_name;
}

uint16_t Player::GetPrestigePoints() const
{
	return m_prestigePoints;
}

void Player::AddPrestigePoints(uint16_t amount)
{
	m_prestigePoints += amount;
}
