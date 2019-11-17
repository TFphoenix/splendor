#pragma once
#include "State.h"
class GameState :
	public State
{

private:
	Entity player;

	void initKeybinds();

public:
	GameState(sf::RenderWindow* windows, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	void updateInput(const float& dt);

	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

