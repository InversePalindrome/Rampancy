/*
Copyright (c) 2017 InversePalindrome
Rampancy - ControlSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "InputManager.hpp"
#include "Tags.hpp"

#include <entityx/System.h>


class ControlSystem : public entityx::System<ControlSystem>, public entityx::Receiver<ControlSystem>
{
public:
    virtual void configure(entityx::EventManager& eventManager) override;
    virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime) override;
    virtual void receive(const entityx::ComponentAddedEvent<Player>& event);

    void setInputManager(const InputManager* inputManager);

private:
    const InputManager* inputManager;
    entityx::Entity player;

    void handleKeyboardInput(entityx::EventManager& eventManager);
    void handleMouseInput(entityx::EventManager& eventManager);
};