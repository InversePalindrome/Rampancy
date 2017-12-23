/*
Copyright (c) 2017 InversePalindrome
Rampancy - PauseDisplay.hpp
InversePalindrome.com
*/


#pragma once

#include <MYGUI/MyGUI_Button.h>


class GameState;

class PauseDisplay 
{
public:
	~PauseDisplay();

	void initialise(GameState* gameState);

	void setVisible(bool visibilityStatus);

private:
	GameState* gameState;

	MyGUI::ButtonPtr resumeButton;
	MyGUI::ButtonPtr quitButton;

	void transitionToGame(MyGUI::WidgetPtr resumeButton);
	void transitionToMenu(MyGUI::WidgetPtr quitButton);
};