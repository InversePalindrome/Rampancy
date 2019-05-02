/*
Copyright (c) 2017 InversePalindrome
Rampancy - MeshComponent.cpp
InversePalindrome.com
*/


#include "MeshComponent.hpp"


MeshComponent::MeshComponent() :
    MeshComponent(nullptr)
{
}

MeshComponent::MeshComponent(Ogre::Entity* entity) :
    Component("Mesh"),
    entity(entity)
{
}

MeshComponent::MeshComponent(Ogre::Entity* entity, Ogre::SceneManager::PrefabType prefabType) :
    Component("Mesh2"),
    entity(entity),
    prefabType(prefabType)
{
}

Ogre::Entity* MeshComponent::getEntity()
{
    return this->entity;
}

Ogre::Entity* MeshComponent::getEntity() const
{
    return this->entity;
}

Ogre::SceneManager::PrefabType MeshComponent::getPrefabType() const
{
    return this->prefabType;
}

void MeshComponent::setEntity(Ogre::Entity* entity)
{
    this->entity = entity;
}

std::ostream& operator<<(std::ostream& os, const MeshComponent& component)
{
    if (component.getName() == "Mesh")
    {
        os << "name " << component.entity->getMesh()->getName();
    }
    else if (component.getName() == "Mesh2")
    {
        os << "prefabType " << component.getPrefabType();
    }

    return os;
}