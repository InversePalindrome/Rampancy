/*
Copyright (c) 2017 InversePalindrome
Rampancy - CameraComponent.hpp
InversePalindrome.com
*/



#pragma once

#include <OGRE/OgreCamera.h>


class CameraComponent
{
public:
	CameraComponent(Ogre::Camera* camera);

	Ogre::Camera* getCamera();

private:
	Ogre::Camera* camera;
};