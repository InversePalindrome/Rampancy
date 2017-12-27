/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.cpp
InversePalindrome.com
*/


#include "MeshComponent.hpp"


MeshComponent::MeshComponent() :
	entity(nullptr)
{
}

MeshComponent::MeshComponent(Ogre::Entity* entity) :
	entity(entity)
{
}

Ogre::Entity* MeshComponent::getEntity()
{
	return this->entity;
}

void MeshComponent::setEntity(Ogre::Entity* entity)
{
	this->entity = entity;
}