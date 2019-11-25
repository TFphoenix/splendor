#include "SessionsManager.h"
#include "PregameSetup.h"
#include "ExpansionCard.h"
#include "UIButton.h"
#include "UIColors.h"
#include "UIPreGameSession.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <unordered_map>

SessionsManager::SessionsManager()
{
	const sf::VideoMode desktopVM = sf::VideoMode().getDesktopMode();
	const sf::VideoMode windowedVM = sf::VideoMode(1280, 720);

	window = new sf::RenderWindow(desktopVM, "Splendor", sf::Style::None);
	//window = new sf::RenderWindow(windowedVM, "Splendor", sf::Style::None);

	windowPosition = window->getPosition();
	windowSize = window->getSize();
}

SessionsManager::~SessionsManager()
{
	delete window;
}

void SessionsManager::MainMenuSession() const
{
	// Background
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("../external/Resources/Images/Backgrounds/Splendor_background.png");
	sf::Sprite background(backgroundTexture);
	background.setScale(windowSize.x / background.getLocalBounds().width, windowSize.y / background.getLocalBounds().height);

	// Main Menu
	sf::RectangleShape mainMenu(sf::Vector2f(400, windowSize.y));
	mainMenu.setPosition(windowSize.x - mainMenu.getSize().x, windowSize.y - mainMenu.getSize().y);
	const auto mainMenuPosition = mainMenu.getPosition();
	const auto mainMenuSize = mainMenu.getSize();
	mainMenu.setFillColor(sf::Color(0, 0, 0, 0));

	// Exit Menu
	sf::RectangleShape exitMenu(sf::Vector2f(800, 200));
	auto exitMenuPosition = exitMenu.getPosition();
	const auto exitMenuSize = exitMenu.getSize();
	exitMenu.setOrigin(exitMenuSize.x / 2.0f, exitMenuSize.y / 2.0f);
	exitMenu.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
	exitMenuPosition = exitMenu.getPosition();
	exitMenu.setFillColor(UIColors::DarkBlue);
	exitMenu.setOutlineColor(UIColors::GoldYellow);
	exitMenu.setOutlineThickness(5.0f);

	// Main Menu Text
	UIText mainMenuText(sf::Vector2f(mainMenuPosition.x + mainMenuSize.x / 2, mainMenuPosition.y + 75), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisLight, "Main Menu", 60);
	mainMenuText.setFillColor(UIColors::GoldYellow);
	mainMenuText.setOutlineThickness(3.0f);
	mainMenuText.AlignText(UIText::TextAlign::mid_center);

	// Exit Menu Text
	UIText exitMenuText(sf::Vector2f(exitMenuPosition.x, exitMenuPosition.y - 50), UIText::TextAlign::mid_center, UIText::AvailableFonts::DosisBold, "Are you sure you want to exit Splendor Game?", 35);
	exitMenuText.setFillColor(UIColors::GoldYellow);
	exitMenuText.setOutlineThickness(0.0f);
	exitMenuText.AlignText(UIText::TextAlign::mid_center);

	// Buttons
	enum class Buttons
	{
		NewGame,
		Tutorial,
		Settings,
		Exit,
		ExitYes,
		ExitNo
	};
	std::unordered_map<Buttons, Collider*> menuButtons;
	sf::RectangleShape buttonShape(sf::Vector2f(300, 80));
	sf::RectangleShape smallButtonShape(sf::Vector2f(100, 50));

	UIButton::Design buttonNoneDesign = {
		UIButton::Design::Body
		{
		sf::Color(0, 0, 0,0),
		UIColors::GoldYellow,
		4.0f
		},
		UIButton::Design::Text
		{
		"Button",
		UIText::AvailableFonts::DosisBold,
		30,
		UIColors::GoldYellow,
		sf::Color(0,0,0),
		0.0f
		}
	};
	UIButton::Design buttonHoverDesign = {
		UIButton::Design::Body
		{
		UIColors::GoldYellow,
		sf::Color(255,255,255),
		2.0f
		},
		UIButton::Design::Text
		{
		"Button",
		UIText::AvailableFonts::DosisBold,
		30,
		sf::Color(255,255,255),
		sf::Color(255,255,255),
		0.0f
		}
	};
	UIButton::Design buttonPressDesign = {
		UIButton::Design::Body
		{
		UIColors::DarkYellow,
		sf::Color(0,0,0),
		0.0f
		},
		UIButton::Design::Text
		{
		"Button",
		UIText::AvailableFonts::DosisBold,
		30,
		sf::Color(200,200,200),
		sf::Color(255,255,255),
		0.0f
		}
	};

	// Main Menu Buttons
	buttonShape.setPosition(sf::Vector2f(mainMenuPosition.x + 50, mainMenuPosition.y + 150));
	menuButtons[Buttons::NewGame] = new UIButton(buttonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::NewGame])->ChangeText("New Game");
	buttonShape.setPosition(sf::Vector2f(mainMenuPosition.x + 50, mainMenuPosition.y + 250));
	menuButtons[Buttons::Tutorial] = new UIButton(buttonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::Tutorial])->ChangeText("Tutorial");
	buttonShape.setPosition(sf::Vector2f(mainMenuPosition.x + 50, mainMenuPosition.y + 350));
	menuButtons[Buttons::Settings] = new UIButton(buttonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::Settings])->ChangeText("Settings");
	buttonShape.setPosition(sf::Vector2f(mainMenuPosition.x + 50, mainMenuPosition.y + 450));
	menuButtons[Buttons::Exit] = new UIButton(buttonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::Exit])->ChangeText("Exit Game");

	// Exit Menu Buttons
	smallButtonShape.setPosition(sf::Vector2f(exitMenuPosition.x - smallButtonShape.getSize().x - 50, exitMenuPosition.y + 20));
	menuButtons[Buttons::ExitYes] = new UIButton(smallButtonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::ExitYes])->ChangeText("Yes");
	smallButtonShape.setPosition(sf::Vector2f(exitMenuPosition.x + 50, exitMenuPosition.y + 20));
	menuButtons[Buttons::ExitNo] = new UIButton(smallButtonShape, buttonNoneDesign, buttonHoverDesign, buttonPressDesign);
	dynamic_cast<UIButton*>(menuButtons[Buttons::ExitNo])->ChangeText("No");


	// Main Menu Session
	bool exitMenuTriggered = false;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (exitMenuTriggered)
			{
				menuButtons[Buttons::ExitYes]->HandleEvent(event);
				menuButtons[Buttons::ExitNo]->HandleEvent(event);
			}
			else
			{
				menuButtons[Buttons::NewGame]->HandleEvent(event);
				menuButtons[Buttons::Tutorial]->HandleEvent(event);
				menuButtons[Buttons::Settings]->HandleEvent(event);
				menuButtons[Buttons::Exit]->HandleEvent(event);
			}

			if (dynamic_cast<UIButton*>(menuButtons[Buttons::NewGame])->GetState() == UIButton::State::Release)
			{
				dynamic_cast<UIButton*>(menuButtons[Buttons::NewGame])->SwitchState(UIButton::State::None);
				PreGameSession();
			}
			if (dynamic_cast<UIButton*>(menuButtons[Buttons::Exit])->GetState() == UIButton::State::Release)
			{
				exitMenuTriggered = true;
			}
			if (dynamic_cast<UIButton*>(menuButtons[Buttons::ExitNo])->GetState() == UIButton::State::Release)
			{
				exitMenuTriggered = false;
				dynamic_cast<UIButton*>(menuButtons[Buttons::Exit])->SwitchState(UIButton::State::None);
				dynamic_cast<UIButton*>(menuButtons[Buttons::ExitNo])->SwitchState(UIButton::State::None);
			}
			if (dynamic_cast<UIButton*>(menuButtons[Buttons::ExitYes])->GetState() == UIButton::State::Release)
			{
				return;
			}
		}

		window->clear();
		window->draw(background);
		window->draw(mainMenu);
		window->draw(mainMenuText);
		window->draw(*menuButtons[Buttons::NewGame]);
		window->draw(*menuButtons[Buttons::Tutorial]);
		window->draw(*menuButtons[Buttons::Settings]);
		window->draw(*menuButtons[Buttons::Exit]);
		if (exitMenuTriggered)
		{
			window->draw(exitMenu);
			window->draw(exitMenuText);
			window->draw(*menuButtons[Buttons::ExitNo]);
			window->draw(*menuButtons[Buttons::ExitYes]);
		}
		window->display();
	}
}

void SessionsManager::PreGameSession() const
{
	UIPreGameSession pregameSessionGUI(windowSize);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			pregameSessionGUI.PassEvent(event);
			if (pregameSessionGUI.BackToMainMenu())
			{
				return;
			}
			if (pregameSessionGUI.StartGame())
			{
				GameSession();
				return;
			}
		}

		window->clear(UIColors::DarkBlue);
		window->draw(pregameSessionGUI);
		window->display();
	}
}

void SessionsManager::GameSession() const
{
	window->clear(UIColors::DarkBlue);
	window->display();
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					return;
				}
			}
		}
	}
	/*uint16_t playerCount;
	std::cin >> playerCount;

	try
	{
		PregameSetup pregameSetup(playerCount);
	}
	catch (const char* errorMessage)
	{
		std::cout << errorMessage;
	}*/
}

void SessionsManager::TestSession() const
{

}

