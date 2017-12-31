/*
Copyright (c) 2017 InversePalindrome
Rampancy - ObjectComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Component.hpp"
#include "ObjectType.hpp"


class ObjectComponent : public Component
{
	friend std::ostream& operator<<(std::ostream& os, const ObjectComponent& component);

public:
	explicit ObjectComponent(ObjectType objectType);

	ObjectType getObjectType() const;

	void setObjectType(ObjectType objectType);

private:
	ObjectType objectType;
};

std::ostream& operator<<(std::ostream& os, const ObjectComponent& component);