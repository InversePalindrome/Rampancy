/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.cpp
InversePalindrome.com
*/


#include "PhysicsComponent.hpp"


PhysicsComponent::PhysicsComponent(Shape shape, btScalar mass) :
	body(nullptr),
	shape(shape),
	mass(mass)
{
}

PhysicsComponent::~PhysicsComponent()
{
	delete this->body->getMotionState();
	delete this->body;
}

btRigidBody* PhysicsComponent::getBody()
{
	return this->body;
}

Shape PhysicsComponent::getShape() const
{
	return this->shape;
}

btScalar PhysicsComponent::getMass() const
{
	return this->mass;
}

void PhysicsComponent::setBody(btRigidBody* body)
{
	this->body = body;
}