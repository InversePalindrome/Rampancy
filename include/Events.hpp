/*
Copyright (c) 2017 InversePalindrome
Rampancy - Events.hpp
InversePalindrome.com
*/


#pragma once

#include <bus.hpp>
#include <event.hpp>

#include <OIS/OISKeyboard.h>


struct KeyPressed
{
    KeyPressed(OIS::KeyCode keyCode) :
        keyCode(keyCode)
    {
    }

    OIS::KeyCode keyCode;
};

using EventBus = eventpp::Bus<KeyPressed>;