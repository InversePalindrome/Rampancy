/*
Copyright (c) 2017 InversePalindrome
Rampancy - CameraComponent.hpp
InversePalindrome.com
*/



#pragma once

#include "Component.hpp"

#include <OGRE/OgreCamera.h>


class CameraComponent : public Component
{
public:
	explicit CameraComponent(Ogre::Camera* camera);

	Ogre::Camera* getCamera();

private:
	Ogre::Camera* camera;
};