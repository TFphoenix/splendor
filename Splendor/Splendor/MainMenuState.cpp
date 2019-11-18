#include "MainMenuState.h"
#include <iostream>
#include <fstream>
#include <sstream>
void MainMenuState::initVariables()
{

}
void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "Failed loaded";
	}


}
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("Could not load font");
	}
	this->background.setTexture(&this->backgroundTexture);

}
void MainMenuState::initKeybinds()
{


	this->keybinds.emplace("Escape", this->supportedKeys->at("Escape"));
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

void MainMenuState::initButtons()
{

	this->buttons["GAME_STATE"] = new Button(300, 380, 150, 50, &this->font, "Start Game", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
	this->buttons["END_STATE"] = new Button(300, 480, 150, 50, &this->font, "Quit", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();



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
	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Quit the game
	if (this->buttons["END_STATE"]->isPressed())
	{
		this->quit = true;
	}
}



void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState!" << " \n";
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
	//Remove later

	//sf::Text mouseText;
	//mouseText.setPosition(this->mousePosView.x,this->mousePosView.y-50);
	//mouseText.setFont(this->font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << this->mousePosView.y;
	//mouseText.setString(ss.str());

	//target->draw(mouseText);

}


