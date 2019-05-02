/*
Copyright (c) 2017 InversePalindrome
Rampancy - SettingsState.cpp
InversePalindrome.com
*/


#include "SettingsState.hpp"
#include "MenuState.hpp"


void SettingsState::OnEnter()
{
    this->backButton = this->getGui()->createWidget<MyGUI::Button>("Button", 0, 0, 150, 50, MyGUI::Align::Default, "Main");
    this->backButton->setCaption("Back");
    this->backButton->eventMouseButtonClick += MyGUI::newDelegate(this, &SettingsState::transitionBack);

    auto* moveUpButton = this->getGui()->createWidget<MyGUI::Button>("Button", 200, 200, 180, 40, MyGUI::Align::Default, "Main");
    moveUpButton->setCaption("Move Up");
    moveUpButton->setUserData(Action::MoveUp);
    actionButtons.push_back(moveUpButton);

    auto* moveDownButton = this->getGui()->createWidget<MyGUI::Button>("Button", 200, 300, 180, 40, MyGUI::Align::Default, "Main");
    moveDownButton->setCaption("Move Down");
    moveDownButton->setUserData(Action::MoveDown);
    actionButtons.push_back(moveDownButton);

    auto* moveRightButton = this->getGui()->createWidget<MyGUI::Button>("Button", 420, 200, 180, 40, MyGUI::Align::Default, "Main");
    moveRightButton->setCaption("Move Right");
    moveRightButton->setUserData(Action::MoveRight);
    actionButtons.push_back(moveRightButton);

    auto* moveLeftButton = this->getGui()->createWidget<MyGUI::Button>("Button", 420, 300, 180, 40, MyGUI::Align::Default, "Main");
    moveLeftButton->setCaption("Move Left");
    moveLeftButton->setUserData(Action::MoveLeft);
    actionButtons.push_back(moveLeftButton);

    auto* moveForwardButton = this->getGui()->createWidget<MyGUI::Button>("Button", 640, 200, 180, 40, MyGUI::Align::Default, "Main");
    moveForwardButton->setCaption("Move Forward");
    moveForwardButton->setUserData(Action::MoveForward);
    actionButtons.push_back(moveForwardButton);

    auto* moveBackwardButton = this->getGui()->createWidget<MyGUI::Button>("Button", 640, 300, 180, 40, MyGUI::Align::Default, "Main");
    moveBackwardButton->setCaption("Move Backward");
    moveBackwardButton->setUserData(Action::MoveBackward);
    actionButtons.push_back(moveBackwardButton);

    for (const auto& controlButton : this->actionButtons)
    {
        controlButton->eventMouseSetFocus += MyGUI::newDelegate(this, &SettingsState::enableChangingControls);
        controlButton->eventKeyLostFocus += MyGUI::newDelegate(this, &SettingsState::disableChangingControls);
    }

    this->actionControls = std::make_shared<ActionControlsListener>(&this->getInputManager());
    this->getEventBus().reg(this->actionControls);
}

void SettingsState::OnExit()
{
    this->getGui()->destroyWidget(this->backButton);

    for (const auto& controlButton : this->actionButtons)
    {
        this->getGui()->destroyWidget(controlButton);
    }

    this->getEventBus().unreg(this->actionControls);
}

hsm::Transition SettingsState::GetTransition()
{
    if (this->getStateTransition() == StateTransition::Menu)
    {
        return hsm::SiblingTransition<MenuState>();
    }

    return hsm::NoTransition();
}

void SettingsState::enableChangingControls(MyGUI::WidgetPtr newButton, MyGUI::WidgetPtr oldButton)
{
    this->actionControls->currentAction = *newButton->getUserData<Action>();
}

void SettingsState::disableChangingControls(MyGUI::WidgetPtr sender, MyGUI::WidgetPtr newFocus)
{
    this->actionControls->currentAction = Action::None;
}

void SettingsState::closeWindow(MyGUI::WidgetPtr window, const std::string& button)
{
    window->setVisible(false);
}

void SettingsState::transitionBack(MyGUI::WidgetPtr backButton)
{
    this->setStateTransition(StateTransition::Menu);
}