/*
Copyright (c) 2017 InversePalindrome
Rampancy - CollisionHandler.hpp
InversePalindrome.com
*/


#pragma once

#include "ObjectType.hpp"

#include <bullet/BulletCollision/BroadphaseCollision/btDispatcher.h>

#include <entityx/Entity.h>

#include <boost/optional/optional.hpp>


class CollisionHandler
{
public:
    explicit CollisionHandler(btDispatcher* dispatcher);

    void update();

private:
    btDispatcher* dispatcher;

    void handleCollision(entityx::Entity entityA, entityx::Entity entityB);

    boost::optional<std::pair<entityx::Entity, entityx::Entity>> collided(entityx::Entity entityA, entityx::Entity entityB,
        ObjectType objectTypeA, ObjectType objectTypeB);
};