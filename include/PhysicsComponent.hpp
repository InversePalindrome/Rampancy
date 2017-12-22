/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.hpp
InversePalindrome.com
*/


#pragma once

#include "Shape.hpp"

#include <bullet/BulletDynamics/Dynamics/btRigidBody.h>


class PhysicsComponent
{
public:
	PhysicsComponent(Shape shape, btScalar mass);
	~PhysicsComponent();

	btRigidBody* getBody();
	Shape getShape() const;
	btScalar getMass() const;

	void setBody(btRigidBody* body);

private:
	btRigidBody * body;
	Shape shape;
	btScalar mass;
};