/*
Copyright (c) 2017 InversePalindrome
Rampancy - ObjectType.hpp
InversePalindrome.com
*/


#pragma once

#include <cstddef>
#include <type_traits>


enum class ObjectType : std::size_t
{ 
	Player = (1 << 0), Enemy = (1 << 1)
};

using T = std::underlying_type_t<ObjectType>;

constexpr ObjectType operator|(const ObjectType objectA, const ObjectType objectB)
{
	return static_cast<ObjectType>(static_cast<T>(objectA) | static_cast<T>(objectB));
}

constexpr T operator&(const ObjectType objectA, const ObjectType objectB)
{
	return static_cast<T>(objectA) & static_cast<T>(objectB);
}