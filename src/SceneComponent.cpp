/*
Copyright (c) 2017 InversePalindrome
Rampancy - SceneComponent.cpp
InversePalindrome.com
*/


#include "SceneComponent.hpp"

 
SceneComponent::SceneComponent() :
	sceneNode(nullptr)
{
}

SceneComponent::SceneComponent(Ogre::SceneNode* sceneNode) :
	sceneNode(sceneNode)
{
}

Ogre::SceneNode* SceneComponent::getSceneNode()
{
	return this->sceneNode;
}

void SceneComponent::setSceneNode(Ogre::SceneNode* sceneNode)
{
	this->sceneNode = sceneNode;
}