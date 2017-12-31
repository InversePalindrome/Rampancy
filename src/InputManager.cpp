/*
Copyright (c) 2017 InversePalindrome
Rampancy - InputManager.cpp
InversePalindrome.com
*/


#include "InputManager.hpp"
#include "FilePaths.hpp"
#include "EnumUtility.hpp"

#include <MYGUI/MyGUI_InputManager.h>

#include <RapidXML/rapidxml.hpp>


void InputManager::setup(Ogre::RenderWindow* window)
{
	std::size_t windowHandle = 0u;

	window->getCustomAttribute("WINDOW", &windowHandle);
	
	this->inputManager = OIS::InputManager::createInputSystem(windowHandle);
	this->keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, true));
	this->mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, true));

	std::size_t width = 0u, height = 0u, depth = 0u;
	std::int32_t left = 0, top = 0;

	window->getMetrics(width, height, depth, left, top);

	const auto& mouseState = this->mouse->getMouseState();
	mouseState.width = width;
	mouseState.height = height;

	this->keyboard->setEventCallback(this);
	this->mouse->setEventCallback(this);

	this->loadKeyBindings();
}

InputManager::~InputManager()
{
	this->inputManager->destroyInputObject(this->keyboard);
	this->inputManager->destroyInputObject(this->mouse);
	this->inputManager->destroyInputSystem(this->inputManager);
}

void InputManager::capture()
{
	if (this->keyboard && this->mouse)
	{
		this->keyboard->capture();
		this->mouse->capture();
	}
}

void InputManager::setAction(Action action, OIS::KeyCode code)
{
	this->keyBindings[action] = code;
}

bool InputManager::keyPressed(const OIS::KeyEvent& event)
{
	MyGUI::InputManager::getInstance().injectKeyPress(MyGUI::KeyCode::Enum(event.key), event.text);
	
	return true;
}

bool InputManager::keyReleased(const OIS::KeyEvent& event)
{
	MyGUI::InputManager::getInstance().injectKeyRelease(MyGUI::KeyCode::Enum(event.key));

	return true;
}

bool InputManager::mouseMoved(const OIS::MouseEvent& event)
{
	MyGUI::InputManager::getInstance().injectMouseMove(event.state.X.abs, event.state.Y.abs, event.state.Z.abs);

	return true;
}

bool InputManager::mousePressed(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
    MyGUI::InputManager::getInstance().injectMousePress(event.state.X.abs, event.state.Y.abs, MyGUI::MouseButton::Enum(id));

	return true;
}

bool InputManager::mouseReleased(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
	MyGUI::InputManager::getInstance().injectMouseRelease(event.state.X.abs, event.state.Y.abs, MyGUI::MouseButton::Enum(id));

	return true;
}

bool InputManager::isActive(Action action) const
{
	if (this->keyboard)
	{
		return this->keyboard->isKeyDown(this->keyBindings.at(action));
	}

	return false;
}

bool InputManager::isKeyPressed() const
{
	if (this->keyboard)
	{
		for (std::size_t i = OIS::KeyCode::KC_UNASSIGNED; i <= OIS::KC_MEDIASELECT; ++i)
		{
			if (this->keyboard->isKeyDown(static_cast<OIS::KeyCode>(i)))
			{
				return true;
			}
		}
	}
	
	return false;
}

void InputManager::loadKeyBindings()
{
	rapidxml::xml_document<> doc;
	std::ifstream inFile(FP::settings + "actions.xml");
	std::ostringstream buffer;

	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	auto* rootNode = doc.first_node("Settings");

	if (rootNode)
	{
		for (auto* node = rootNode->first_node("Key"); node; node = node->next_sibling())
		{
			Action action;
			OIS::KeyCode keyCode;

			std::stringstream stream;
			stream << node->first_attribute("action")->value() << ' ' << node->first_attribute("code")->value();
			stream >> action >> keyCode;

			this->keyBindings[action] = keyCode;
		}
	}
}