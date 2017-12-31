/*
Copyright (c) 2017 InversePalindrome
Rampancy - MenuState.cpp
InversePalindrome.com
*/


#include "MenuState.hpp"
#include "GameState.hpp"
#include "SettingsState.hpp"
#include "FilePaths.hpp"

#include <MYGUI/MyGUI_TextBox.h>
#include <MYGUI/MyGUI_EditBox.h>
#include <MYGUI/MyGUI_ListBox.h>

#include <boost/filesystem/operations.hpp>


void MenuState::OnEnter()
{
	this->newGameButton = this->getGui()->createWidget<MyGUI::Button>("Button", 75, 
		140, 250, 50, MyGUI::Align::Default, "Main");
	this->newGameButton->setCaption("New Game");
	this->newGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::openNewGameTab);

	this->loadGameButton = this->getGui()->createWidget<MyGUI::Button>("Button", 75,
		240, 250, 50, MyGUI::Align::Default, "Main");
	this->loadGameButton->setCaption("Load Game");
	this->loadGameButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::openLoadedGamesTab);

	this->settingsButton = this->getGui()->createWidget<MyGUI::Button>("Button", 75,
		340, 250, 50, MyGUI::Align::Default, "Main");
	this->settingsButton->setCaption("Settings");
	this->settingsButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::transitionToSettings);

	this->quitButton = this->getGui()->createWidget<MyGUI::Button>("Button", 75,
		440, 250, 50, MyGUI::Align::Default, "Main");
	this->quitButton->setCaption("Quit");
	this->quitButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::quitApp);

	this->newGameWindow = this->getGui()->createWidget<MyGUI::Window>("WindowCSX", 450, 220, 300, 200, MyGUI::Align::Default, "Main");
	this->newGameWindow->setCaption("New Game");
	this->newGameWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &MenuState::closeWindow);

	auto* nameLabel = this->getGui()->createWidget<MyGUI::TextBox>("TextBox", 105, 10, 100, 50, MyGUI::Align::Default, "Main");
	nameLabel->setCaption("Name");
	nameLabel->attachToWidget(newGameWindow);

	auto* nameEntry = this->getGui()->createWidget<MyGUI::EditBox>("EditBox", 10, 50, 270, 50, MyGUI::Align::Default, "Main", "NameEntry");
	nameEntry->attachToWidget(newGameWindow);

	auto* addButton = this->getGui()->createWidget<MyGUI::Button>("Button", 10, 105, 270, 50, MyGUI::Align::Default, "Main");
	addButton->setCaption("Add");
	addButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::addGame);
	addButton->attachToWidget(newGameWindow);

	this->newGameWindow->setVisible(false);
	
	this->loadGameWindow = this->getGui()->createWidget<MyGUI::Window>("WindowCSX", 450, 150, 300, 325, MyGUI::Align::Default, "Main");
	this->loadGameWindow->setCaption("Load Game");
	this->loadGameWindow->eventWindowButtonPressed += MyGUI::newDelegate(this, &MenuState::closeWindow);

	auto* gameList = this->getGui()->createWidget<MyGUI::ListBox>("ListBox", 15, 10, 260, 210, MyGUI::Align::Default, "Main", "GameList");
	gameList->attachToWidget(loadGameWindow);
	
	for (const auto& game : this->getGames())
	{
		gameList->addItem(game.second.getName());
	}

	auto* playButton = this->getGui()->createWidget<MyGUI::Button>("Button", 15, 230, 130, 50, MyGUI::Align::Default, "Main");
	playButton->setCaption("Play");
	playButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::transitionToGame);
	playButton->attachToWidget(loadGameWindow);

	auto* deleteButton = this->getGui()->createWidget<MyGUI::Button>("Button", 145, 230, 130, 50, MyGUI::Align::Default, "Main");
	deleteButton->setCaption("Delete");
	deleteButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MenuState::deleteGame);
	deleteButton->attachToWidget(loadGameWindow);

	this->loadGameWindow->setVisible(false);
}

void MenuState::OnExit()
{
	this->getGui()->destroyWidget(this->newGameButton);
	this->getGui()->destroyWidget(this->loadGameButton);
	this->getGui()->destroyWidget(this->settingsButton);
	this->getGui()->destroyWidget(this->quitButton);
	this->getGui()->destroyWidget(this->newGameWindow);
	this->getGui()->destroyWidget(this->loadGameWindow);
}

hsm::Transition MenuState::GetTransition()
{
	if (this->getStateTransition() == StateTransition::Game)
	{
		return hsm::SiblingTransition<GameState>();
	}
	else if (this->getStateTransition() == StateTransition::Settings)
	{
		return hsm::SiblingTransition<SettingsState>();
	}

	return hsm::NoTransition();
}

void MenuState::openNewGameTab(MyGUI::WidgetPtr newGameButton)
{
	this->loadGameWindow->setVisible(false);
	this->newGameWindow->setVisible(true);
}

void MenuState::openLoadedGamesTab(MyGUI::WidgetPtr loadGameButton)
{
	this->newGameWindow->setVisible(false);
	this->loadGameWindow->setVisible(true);
}

void MenuState::addGame(MyGUI::WidgetPtr addGameButton)
{
	auto* editBox = this->getGui()->findWidget<MyGUI::EditBox>("NameEntry");

	if (!editBox->getCaption().empty() && !this->getGames().hasGame(editBox->getCaption()))
	{
		auto* gameList = this->getGui()->findWidget<MyGUI::ListBox>("GameList");

		const std::string& gameName = editBox->getCaption();

		gameList->addItem(gameName);

		this->newGameWindow->setVisible(false);
		
		this->getGames().addGame(gameName);

		boost::filesystem::create_directory(FP::savedGames + '/' + gameName);

		editBox->setCaption("");
	}
}

void MenuState::deleteGame(MyGUI::WidgetPtr deleteGameButton)
{
	auto* gameList = this->getGui()->findWidget<MyGUI::ListBox>("GameList");

	if (gameList->isItemSelectedVisible())
	{
		const std::string& gameName = gameList->getItemNameAt(gameList->getIndexSelected());

		this->getGames().removeGame(gameName);

		gameList->removeItemAt(gameList->getIndexSelected());
		
		boost::filesystem::remove_all(FP::savedGames + '/' + gameName + '/');
	}
}

void MenuState::closeWindow(MyGUI::WidgetPtr window, const std::string& button)
{
	window->setVisible(false);
}

void MenuState::transitionToGame(MyGUI::WidgetPtr playButton)
{
	auto* gameList = this->getGui()->findWidget<MyGUI::ListBox>("GameList");

	if (gameList->isItemSelectedVisible())
	{
		this->getGames().setCurrentGame(gameList->getItemNameAt(gameList->getIndexSelected()));

		this->setStateTransition(StateTransition::Game);
	}
}

void MenuState::transitionToSettings(MyGUI::WidgetPtr settingsButton)
{
	this->setStateTransition(StateTransition::Settings);
}

void MenuState::quitApp(MyGUI::WidgetPtr quitButton)
{
	this->setShutdown(true);
}