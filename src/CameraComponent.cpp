/*
Copyright (c) 2017 InversePalindrome
Rampancy - CameraComponent.cpp
InversePalindrome.com
*/


#include "CameraComponent.hpp"


CameraComponent::CameraComponent(Ogre::Camera* camera) :
	Component("Camera"),
	camera(camera)
{
}

Ogre::Camera* CameraComponent::getCamera()
{
	return this->camera;
}