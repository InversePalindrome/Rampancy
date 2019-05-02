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
    friend std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component);

public:
    PhysicsComponent(Shape shape, btScalar mass, float movementImpulse, float rotationImpulse, float movementDamping, float rotationDamping);
    ~PhysicsComponent();

    btRigidBody* getBody();
    btVector3 getPosition() const;
    btQuaternion getRotation() const;
    Shape getShape() const;
    btScalar getMass() const;
    float getMovementImpulse() const;
    float getRotationImpulse() const;
    float getMovementDamping() const;
    float getRotationDamping() const;


    void setBody(btRigidBody* body);
    void setPosition(const btVector3& position);
    void setRotation(const btQuaternion& rotation);

private:
    btRigidBody* body;

    Shape shape;
    btScalar mass;

    float movementImpulse;
    float rotationImpulse;
    float movementDamping;
    float rotationDamping;
};

std::ostream& operator<<(std::ostream& os, const PhysicsComponent& component);