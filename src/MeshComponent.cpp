/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.cpp
InversePalindrome.com
*/


#include "MeshComponent.hpp"


MeshComponent::MeshComponent(Ogre::Entity* entity, Ogre::SceneNode* sceneNode) :
	entity(entity),
	sceneNode(sceneNode)
{
	sceneNode->attachObject(entity);
}

Ogre::Entity* MeshComponent::getEntity()
{
	return this->entity;
}

Ogre::SceneNode* MeshComponent::getSceneNode()
{
	return this->sceneNode;
}