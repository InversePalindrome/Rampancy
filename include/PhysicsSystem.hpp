/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "EntityEvents.hpp"
#include "MeshComponent.hpp"
#include "CameraComponent.hpp"
#include "CollisionHandler.hpp"

#include <bullet/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <bullet/BulletCollision/BroadphaseCollision/btDispatcher.h>
#include <bullet/BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>
#include <bullet/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <bullet/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>

#include <entityx/System.h>

#include <list>


class PhysicsSystem : public entityx::System<PhysicsSystem>, public entityx::Receiver<PhysicsSystem>
{
public:
    PhysicsSystem();
    ~PhysicsSystem();

    virtual void configure(entityx::EventManager& eventManager) override;
    virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& eventManager, entityx::TimeDelta deltaTime) override;
    virtual void receive(const CreatePhysicalBody& event);
    virtual void receive(const ChangeDirection& event);
    virtual void receive(const ChangeRotation& event);

private:
    btBroadphaseInterface* broadPhase;
    btDefaultCollisionConfiguration* configuration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* world;

    CollisionHandler collisionHandler;

    std::list<entityx::Entity> physicalEntities;
};