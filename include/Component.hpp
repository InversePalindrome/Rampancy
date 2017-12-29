/*
Copyright (c) 2017 InversePalindrome
Rampancy - Component.hpp
InversePalindrome.com
*/


#pragma once

#include <string>


class Component
{
public:
	Component(const std::string& name);

	std::string getName() const;

private:
	std::string name;
};


std::ostream& operator<<(std::ostream& os, const Component& component);