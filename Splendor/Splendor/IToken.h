#pragma once

class IToken
{
public:
	enum class Type
	{
		GreenEmerald,
		BlueSapphire,
		WhiteDiamond,
		BlackOnyx,
		RedRuby,
		Gold
	};

public:
	virtual ~IToken() = 0;

private:

};

