/*
Copyright (c) 2017 InversePalindrome
Rampancy - EnumUtility.hpp
InversePalindrome.com
*/


#pragma once

#include <type_traits>


template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::istream&>::type
operator >>(std::istream& is, T& enumVar)
{
    std::size_t value = 0u;
    is >> value;

    enumVar = static_cast<T>(value);

    return is;
}

template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::ostream&>::type
operator <<(std::ostream& os, T& enumVar)
{
    auto value = static_cast<std::size_t>(enumVar);

    os << value;

    return os;
}