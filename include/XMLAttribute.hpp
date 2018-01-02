/*
Copyright (c) 2017 InversePalindrome
Rampancy - XMLAttribute.hpp
InversePalindrome.com
*/


#pragma once

#include <RapidXML/rapidxml.hpp>

#include <string>
#include <type_traits>


class XMLAttribute
{
public:
	explicit XMLAttribute(const rapidxml::xml_node<char>* xmlNode);

	template<typename T>
	std::string value(const std::string& name) const;

private:
	const rapidxml::xml_node<char>* xmlNode;
};


template<typename T>
std::string XMLAttribute::value(const std::string& name) const
{
	std::string value;

	if (this->xmlNode && this->xmlNode->first_attribute(name.c_str()))
	{
		return this->xmlNode->first_attribute(name.c_str())->value();
	}
	else if (std::is_same<T, std::string>::value)
	{
		return value;
    }
	else if (std::is_same<T, float>::value)
	{
		return std::to_string(0.f);
	}
	else if (std::is_same<T, std::size_t>::value)
	{
		return std::to_string(0u);
	}

	return value;
}