/*
Copyright (c) 2017 InversePalindrome
Rampancy - Components.hpp
InversePalindrome.com
*/


#pragma once

#include "MeshComponent.hpp"
#include "SceneComponent.hpp"
#include "CameraComponent.hpp"
#include "LightComponent.hpp"
#include "PhysicsComponent.hpp"
#include "ObjectComponent.hpp"
#include "Tags.hpp"

#include <brigand/sequences/list.hpp>


using Components = brigand::list<PhysicsComponent, ObjectComponent, SceneComponent, MeshComponent, LightComponent, CameraComponent,
    Player>;