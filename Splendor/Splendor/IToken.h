#pragma once

class IToken
{
public:
	enum class Type
	{
		GreenEmerald,
		BlueSapphire,
		WhiteDiamond,
		blackOnyx,
		RedRuby,
		Gold
	};

public:
	virtual ~IToken() = 0;

private:

};

