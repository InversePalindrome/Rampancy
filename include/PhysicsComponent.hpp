/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Shape.hpp"
#include "Component.hpp"

#include <bullet/BulletDynamics/Dynamics/btRigidBody.h>


class PhysicsComponent : public Component
{
	friend std::istream& operator>>(std::istream& is, PhysicsComponent& component);
	friend std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component);

public:
	PhysicsComponent(Shape shape, btScalar mass, float impulse, float damping);
	~PhysicsComponent();

	btRigidBody* getBody();
	btVector3 getPosition() const;
	btQuaternion getRotation() const;
	Shape getShape() const;
	btScalar getMass() const;
	float getImpulse() const;
	float getDamping() const;

	void setBody(btRigidBody* body);

private:
	btRigidBody * body;
	Shape shape;
	btScalar mass;
	float impulse;
	float damping;
};

std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component);