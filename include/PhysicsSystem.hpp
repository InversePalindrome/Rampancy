/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsSystem.hpp
InversePalindrome.com
*/


#pragma once

#include "MeshComponent.hpp"

#include <bullet/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <bullet/BulletCollision/BroadphaseCollision/btDispatcher.h>
#include <bullet/BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>
#include <bullet/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <bullet/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>

#include <entityx/System.h>


class PhysicsSystem : public entityx::System<PhysicsSystem>, public entityx::Receiver<entityx::ComponentAddedEvent<PhysicsSystem>>
{
public:
	PhysicsSystem();
	~PhysicsSystem();

	virtual void configure(entityx::EventManager& eventManager) override;
	virtual void update(entityx::EntityManager& entityManager, entityx::EventManager& events, entityx::TimeDelta deltaTime) override;
	virtual void receive(const entityx::ComponentAddedEvent<MeshComponent>& event);
	
private:
	btBroadphaseInterface* broadPhase;
	btDefaultCollisionConfiguration* configuration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* world;
};