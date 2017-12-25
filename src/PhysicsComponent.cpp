/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.cpp
InversePalindrome.com
*/


#include "PhysicsComponent.hpp"


PhysicsComponent::PhysicsComponent(Shape shape, btScalar mass, float impulse, float damping) :
	body(nullptr),
	shape(shape),
	mass(mass),
	impulse(impulse),
	damping(damping)
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

float PhysicsComponent::getImpulse() const
{
	return this->impulse;
}

float PhysicsComponent::getDamping() const
{
	return this->damping;
}

void PhysicsComponent::setBody(btRigidBody* body)
{
	this->body = body;
	this->body->setActivationState(DISABLE_DEACTIVATION);
	this->body->setDamping(this->damping, 0.f);
}