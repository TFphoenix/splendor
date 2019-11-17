#include "MainMenuState.h"
#include <iostream>
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("Could not load font");
	}

}
void MainMenuState::initKeybinds()
{ 
	this->keybinds.emplace("Escape", this->supportedKeys->at("Esc"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

void MainMenuState::initButtons()
{

	this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->font, "Start Game", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
	this->buttons["END_STATE"] = new Button(100, 300, 150, 50, &this->font, "Quit", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{

	this->initFonts();
	this->initKeybinds();
	this->initButtons();


	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Yellow);
}
MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))


}

void MainMenuState::updateButtons()
{

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Quit the game
	if (this->buttons["END_STATE"]->isPressed())
	{
		this->quit = true;
	}
}



void MainMenuState::endState()
{
	std::cout << "Ending GameState!" << " \n";
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	//this->gamestate_btm->render(target);
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);


}


