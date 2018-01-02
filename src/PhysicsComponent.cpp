/*
Copyright (c) 2017 InversePalindrome
Rampancy - PhysicsComponent.cpp
InversePalindrome.com
*/


#include "PhysicsComponent.hpp"
#include "EnumUtility.hpp"


PhysicsComponent::PhysicsComponent(Shape shape, btScalar mass, float movementImpulse, float rotationImpulse, float movementDamping, float rotationDamping) :
	Component("Physics"),
	body(nullptr),
	shape(shape),
	mass(mass),
	movementImpulse(movementImpulse),
	rotationImpulse(rotationImpulse),
	movementDamping(movementDamping),
	rotationDamping(rotationDamping)
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

float PhysicsComponent::getMovementImpulse() const
{
	return this->movementImpulse;
}

float PhysicsComponent::getRotationImpulse() const
{
	return this->rotationImpulse;
}

float PhysicsComponent::getMovementDamping() const
{
	return this->movementDamping;
}

float PhysicsComponent::getRotationDamping() const
{
	return this->rotationDamping;
}

void PhysicsComponent::setBody(btRigidBody* body)
{
	this->body = body;
	this->body->setActivationState(DISABLE_DEACTIVATION);
	this->body->setDamping(this->movementDamping, this->rotationDamping);
}

void PhysicsComponent::setPosition(const btVector3& position)
{
	auto transform = this->body->getCenterOfMassTransform();
	 
	transform.setOrigin(position);

	this->body->setCenterOfMassTransform(transform);
}

void PhysicsComponent::setRotation(const btQuaternion& rotation)
{
	auto transform = this->body->getCenterOfMassTransform();

	transform.setRotation(rotation);

	this->body->setCenterOfMassTransform(transform);
}

std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component)
{
	os << "shape " << component.shape << " mass " << component.mass << " movementImpulse " << component.movementImpulse <<
		" rotationImpulse " << component.rotationImpulse << " movementDamping " << component.movementDamping << " rotationDamping " << component.rotationDamping;

	return os;
}