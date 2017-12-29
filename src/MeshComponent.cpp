/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.cpp
InversePalindrome.com
*/


#include "MeshComponent.hpp"


MeshComponent::MeshComponent() :
	MeshComponent(nullptr)
{
}

MeshComponent::MeshComponent(Ogre::Entity* entity) :
	Component("Mesh"),
	entity(entity)
{
}

Ogre::Entity* MeshComponent::getEntity()
{
	return this->entity;
}

Ogre::Entity* MeshComponent::getEntity() const
{
	return this->entity;
}

void MeshComponent::setEntity(Ogre::Entity* entity)
{
	this->entity = entity;
}

std::ostream& operator<<(std::ostream& os, const MeshComponent& component)
{
	os << "name " << component.entity->getMesh()->getName();

	return os;
}