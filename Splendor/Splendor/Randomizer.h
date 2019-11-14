#pragma once
#include <random>

class Randomizer
{
public:
	Randomizer();
	uint16_t Generate(uint16_t minim, uint16_t maxim);
	int Generate(int minim, int maxim);
	float Generate(float minim, float maxim);

private:
	std::random_device randomDevice;
	std::mt19937 m_MTwister;
};