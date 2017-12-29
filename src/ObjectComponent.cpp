/*
Copyright (c) 2017 InversePalindrome
Rampancy - ObjectComponent.cpp
InversePalindrome.com
*/


#include "ObjectComponent.hpp"
#include "EnumUtility.hpp"


ObjectComponent::ObjectComponent(ObjectType objectType) :
	Component("Object"),
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

std::ostream& operator<<(std::ostream& os, const ObjectComponent& component)
{
	os << "type " << component.objectType;
	
	return os;
}