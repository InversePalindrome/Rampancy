/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsSystem.cpp
InversePalindrome.com
*/


#include "PhysicsSystem.hpp"
#include "PhysicsComponent.hpp"

#include <BtOgreGP.h>
#include <BtOgrePg.h>

#include <bullet/BulletDynamics/Dynamics/btRigidBody.h>
#include <bullet/BulletCollision/BroadphaseCollision/btDbvtBroadphase.h>


PhysicsSystem::PhysicsSystem() :
	broadPhase(new btDbvtBroadphase()),
	configuration(new btDefaultCollisionConfiguration()),
	dispatcher(new btCollisionDispatcher(configuration)),
	solver(new btSequentialImpulseConstraintSolver()),
	world(new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, configuration))
{
	world->setGravity({ 0.f, -9.81f, 0.f });
}

PhysicsSystem::~PhysicsSystem()
{
	delete this->world;
	delete this->solver;
	delete this->configuration;
	delete this->dispatcher;
	delete this->broadPhase;
}

void PhysicsSystem::configure(entityx::EventManager& eventManager)
{
	eventManager.subscribe<entityx::ComponentAddedEvent<MeshComponent>>(*this);
}

void PhysicsSystem::update(entityx::EntityManager& entityManager, entityx::EventManager& events, entityx::TimeDelta deltaTime)
{
	this->world->stepSimulation(1 / 60.f, 10);
}

void PhysicsSystem::receive(const entityx::ComponentAddedEvent<MeshComponent>& event)
{
	auto entity = event.entity;

	auto physics = entity.component<PhysicsComponent>();
	auto mesh = entity.component<MeshComponent>();
	
	if (physics)
	{
		auto* motionState = new BtOgre::RigidBodyState(mesh->getSceneNode());
		BtOgre::StaticMeshToShapeConverter converter(mesh->getEntity());

		btVector3 localInertia;
		btCollisionShape* shape = nullptr;

		switch (physics->getShape())
		{
		case Shape::Sphere:
			shape = converter.createSphere();
			break;
		case Shape::Box:
			shape = converter.createBox();
			break;
		case Shape::Triangle:
			shape = converter.createTrimesh();
			break;
		case Shape::Cylinder:
			shape = converter.createCylinder();
			break;
		case Shape::ConvexHull:
			shape = converter.createCapsule();
			break;
		case Shape::Capsule:
			shape = converter.createCapsule();
			break;
		}

		shape->calculateLocalInertia(physics->getMass(), localInertia);
		
		physics->setBody(new btRigidBody(physics->getMass(), motionState, shape, localInertia));

		this->world->addRigidBody(physics->getBody());
	}
}