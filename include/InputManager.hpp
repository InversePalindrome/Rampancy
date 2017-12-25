/*
Copyright (c) 2017 InversePalindrome
Rampancy - InputManager.hpp
InversePalindrome.com
*/


#pragma once

#include "Actions.hpp"

#include <OGRE/OgreRenderWindow.h>

#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>

#include <unordered_map>


class InputManager : public OIS::KeyListener, public OIS::MouseListener
{
public:
	InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	void initialise(Ogre::RenderWindow* window);
	~InputManager();

	void capture();

	void setAction(Action action, OIS::KeyCode code);

	virtual bool keyPressed(const OIS::KeyEvent& event) override;
	virtual bool keyReleased(const OIS::KeyEvent& event) override;

	virtual bool mouseMoved(const OIS::MouseEvent& event) override;
	virtual bool mousePressed(const OIS::MouseEvent& event, OIS::MouseButtonID id) override;
	virtual bool mouseReleased(const OIS::MouseEvent& event, OIS::MouseButtonID id) override;

	bool isActive(Action action) const;
	bool isKeyPressed() const;

	void loadKeyBindings();

private:
	OIS::InputManager* inputManager;
	OIS::Keyboard* keyboard;
	OIS::Mouse* mouse;

	std::unordered_map<Action, OIS::KeyCode> keyBindings;
};