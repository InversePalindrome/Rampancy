/*
Copyright (c) 2017 InversePalindrome
Rampancy - Game.hpp
InversePalindrome.com
*/


#pragma once

#include <string>


class Game
{
public:
    Game() = default;
    explicit Game(const std::string& name);

    std::string getName() const;

private:
    std::string name;
};