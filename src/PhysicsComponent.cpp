/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.cpp
InversePalindrome.com
*/


#include "PhysicsComponent.hpp"
#include "EnumUtility.hpp"


PhysicsComponent::PhysicsComponent(Shape shape, btScalar mass, float impulse, float damping) :
	Component("Physics"),
	body(nullptr),
	shape(shape),
	mass(mass),
	impulse(impulse),
	damping(damping)
{
}

PhysicsComponent::~PhysicsComponent()
{
	delete body->getMotionState();
	delete body;
}

btRigidBody* PhysicsComponent::getBody()
{
	return this->body;
}

btVector3 PhysicsComponent::getPosition() const
{
	return this->body->getCenterOfMassPosition();
}

btQuaternion PhysicsComponent::getRotation() const
{
	return this->body->getCenterOfMassTransform().getRotation();
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

std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component)
{
	os << "shape " << component.shape << " mass " << component.mass
		<< " impulse " << component.impulse << " damping " << component.damping;

	return os;
}