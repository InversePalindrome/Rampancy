/*
Copyright (c) 2017 InversePalindrome
Rampancy - SceneComponent.cpp
InversePalindrome.com
*/


#include "SceneComponent.hpp"


SceneComponent::SceneComponent() :
    SceneComponent(nullptr)
{
}

SceneComponent::SceneComponent(Ogre::SceneNode* sceneNode) :
    Component("Scene"),
    sceneNode(sceneNode)
{
}

Ogre::SceneNode* SceneComponent::getSceneNode()
{
    return this->sceneNode;
}

Ogre::Vector3 SceneComponent::getPosition() const
{
    return this->sceneNode->getPosition();
}

Ogre::Quaternion SceneComponent::getRotation() const
{
    return this->sceneNode->getOrientation();
}

void SceneComponent::setSceneNode(Ogre::SceneNode* sceneNode)
{
    this->sceneNode = sceneNode;
}