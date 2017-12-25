/*
Copyright (c) 2017 InversePalindrome
Rampancy - ObjectComponent.cpp
InversePalindrome.com
*/


#include "ObjectComponent.hpp"


ObjectComponent::ObjectComponent(ObjectType objectType) :
	objectType(objectType)
{
}

ObjectType ObjectComponent::getObjectType() const
{
	return this->objectType;
}

void ObjectComponent::setObjectType(ObjectType objectType)
{
	this->objectType = objectType;
}