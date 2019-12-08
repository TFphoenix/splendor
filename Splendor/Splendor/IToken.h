#pragma once

class IToken
{
public:
	enum class Type
	{
		GreenEmerald = 1,
		BlueSapphire = 3,
		WhiteDiamond = 2,
		BlackOnyx = 0,
		RedRuby = 4,
		Gold = 5
	};

public:
	virtual ~IToken() = 0;

private:

};

