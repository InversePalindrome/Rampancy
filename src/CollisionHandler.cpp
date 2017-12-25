/*
Copyright (c) 2017 InversePalindrome
Rampancy - CollisionHandler.cpp
InversePalindrome.com
*/


#include "CollisionHandler.hpp"
#include "ObjectComponent.hpp"

#include <bullet/BulletCollision/CollisionDispatch/btCollisionObject.h>
#include <bullet/BulletCollision/NarrowPhaseCollision/btPersistentManifold.h>


CollisionHandler::CollisionHandler(btDispatcher* dispatcher) :
	dispatcher(dispatcher)
{
}

void CollisionHandler::update()
{
	for (int i = 0; i < dispatcher->getNumManifolds(); ++i)
	{
		auto* contactManifold = dispatcher->getManifoldByIndexInternal(i);
		
		for (int j = 0; j < contactManifold->getNumContacts(); ++j)
		{
			const auto& point = contactManifold->getContactPoint(j);

			if (point.getDistance() < 0.f)
			{
	            const auto* objectA = static_cast<const btCollisionObject*>(contactManifold->getBody0());
				const auto* objectB = static_cast<const btCollisionObject*>(contactManifold->getBody1());
				 
				const auto* entityA = static_cast<entityx::Entity*>(objectA->getUserPointer());
			    const auto* entityB = static_cast<entityx::Entity*>(objectB->getUserPointer());
				
				this->handleCollision(*entityA, *entityB);
			}
		}
	}
}

void CollisionHandler::handleCollision(entityx::Entity entityA, entityx::Entity entityB)
{
	if (const auto& collisionPair = this->collided(entityA, entityB, ObjectType::Player, ObjectType::Enemy))
	{
		
	}
}

boost::optional<std::pair<entityx::Entity, entityx::Entity>> CollisionHandler::collided(entityx::Entity entityA, entityx::Entity entityB,
	ObjectType objectTypeA, ObjectType objectTypeB)
{
	auto objectA = entityA.component<ObjectComponent>();
	auto objectB = entityB.component<ObjectComponent>();

	if (objectA && objectB)
	{
		if (objectA->getObjectType() & objectTypeA && objectB->getObjectType() & objectTypeB)
		{
			return std::make_pair(entityA, entityB);
		}
		else if (objectA->getObjectType() & objectTypeB && objectB->getObjectType() & objectTypeA)
		{
			return std::make_pair(entityB, entityA);
		}
	}

	return {};
}