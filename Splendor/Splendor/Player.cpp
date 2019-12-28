#include "Player.h"

Player::Player(std::string&& name, Type type) :
	m_name(std::move(name)),
	m_type(type),
	m_prestigePoints(0) {}

std::string Player::GetName() const
{
	return m_name;
}

Player::Type Player::GetType() const
{
	return m_type;
}

uint16_t Player::GetPrestigePoints() const
{
	return m_prestigePoints;
}

Hand Player::GetHand() const
{
	return m_hand;
}

void Player::AddPrestigePoints(uint16_t amount)
{
	m_prestigePoints += amount;
}
