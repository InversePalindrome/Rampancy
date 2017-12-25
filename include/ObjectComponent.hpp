/*
Copyright (c) 2017 InversePalindrome
Rampancy - ObjectComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "ObjectType.hpp"


class ObjectComponent
{
public:
	ObjectComponent(ObjectType objectType);

	ObjectType getObjectType() const;

	void setObjectType(ObjectType objectType);

private:
	ObjectType objectType;
};