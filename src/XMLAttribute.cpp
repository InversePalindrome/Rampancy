/*
Copyright (c) 2017 InversePalindrome
Rampancy - XMLAttribute.cpp
InversePalindrome.com
*/


#include "XMLAttribute.hpp"


XMLAttribute::XMLAttribute(const rapidxml::xml_node<char>* xmlNode) :
    xmlNode(xmlNode)
{
}

std::string XMLAttribute::value(const std::string& name, const std::string& optionalValue)
{
    if (this->xmlNode && this->xmlNode->first_attribute(name.c_str()))
    {
        return this->xmlNode->first_attribute(name.c_str())->value();
    }

    return optionalValue;
}