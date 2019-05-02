/*
Copyright (c) 2017 InversePalindrome
Rampancy - Component.cpp
InversePalindrome.com
*/


#include "Component.hpp"


Component::Component(const std::string& name) :
    name(name)
{
}

std::string Component::getName() const
{
    return this->name;
}

std::ostream& operator<<(std::ostream& os, const Component& component)
{
    return os;
}